#include "Actor_FishClowds.h"
#include "Components/SplineComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Engine/Texture2D.h"
#include "Rendering/Texture2DResource.h"
#include "RHICommandList.h"
#include "RenderUtils.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/TextureDefines.h" // For EPixelFormat enums
#include "Misc/ScopeExit.h"

AActor_FishClowds::AActor_FishClowds()
{
	PrimaryActorTick.bCanEverTick = false;

	SplineComp = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComp"));
	SetRootComponent(SplineComp);

	HISM = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("HISM"));

	SplineComp->SetClosedLoop(true);
	RuntimeTexture = nullptr;
	DynamicMID = nullptr;

	// --- CPU 부담 최소화 세팅 ---
	//HISM->SetMobility(EComponentMobility::Static); // 움직이지 않음
	HISM->bCastDynamicShadow = false;               // 그림자 계산 생략
	HISM->bAffectDistanceFieldLighting = false;
	//HISM->bEvaluateWorldPositionOffset = false;    // 머티리얼 OIT/WorldPositionOffset 계산 안함
	HISM->NumCustomDataFloats = 0;                 // 커스텀 데이터 없음
	HISM->SetCollisionEnabled(ECollisionEnabled::NoCollision); // 충돌 끔
	HISM->bSelectable = false;                    // 에디터 선택 최소화
	HISM->bEnableDensityScaling = false;

	// LOD & Cull 최적화
	HISM->SetCullDistances(0, 10000); // 필요에 맞게 조절

	// Rendering 최적화
	HISM->bRenderInMainPass = true;
	HISM->bRenderCustomDepth = false;

	HISM->SetupAttachment(RootComponent);
}

void AActor_FishClowds::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	// Optional: build texture in editor when placing actor
	// BuildSplineTexture();
}

void AActor_FishClowds::BeginPlay()
{
	Super::BeginPlay();
	SetInstanceCount(ISMCount);
	BuildSplineTexture();
}

void AActor_FishClowds::SetInstanceCount(const int TargetCount)
{
	if (!HISM)
	{
		UE_LOG(LogTemp, Warning, TEXT("HISM is null"));
		return;
	}
	const int32 CurrentCount = HISM->GetInstanceCount();
	if (CurrentCount < TargetCount)
	{
		const int32 ToAdd = TargetCount - CurrentCount;
		for (int32 i = 0; i < ToAdd; ++i)
		{
			FTransform InstanceTransform;
			//float normalizelength = (static_cast<float>(i + CurrentCount) / static_cast<float>(TargetCount));
			//const FVector Location = SplineComp->GetLocationAtDistanceAlongSpline(normalizelength * SplineComp->GetSplineLength(), ESplineCoordinateSpace::Local);
			//InstanceTransform.SetLocation(Location);
			//nstanceTransform.SetScale3D(FVector(1.f, 1.f, 1.f));
			HISM->AddInstance(InstanceTransform);
		}
	}
	else if (CurrentCount > TargetCount)
	{
		const int32 ToRemove = CurrentCount - TargetCount;
		for (int32 i = 0; i < ToRemove; ++i)
		{
			HISM->RemoveInstance(CurrentCount - 1 - i);
		}
	}
}

void AActor_FishClowds::BuildSplineTexture()
{
	if (!SplineComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("SplineComp is null"));
		return;
	}

	const int32 NumPoints = SplineComp->GetNumberOfSplinePoints();
	if (NumPoints <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spline has no points"));
		return;
	}

	// We'll use Width = NumPoints, Height = 2 (row0 = Position, row1 = Tangent)
	const int32 Width = NumPoints;
	const int32 Height = 2;

	// Create transient float RGBA texture
	// Use PF_A32B32G32R32F (RGBA 32-bit float). In engine code the enum is PF_A32B32G32R32F
	RuntimeTexture = UTexture2D::CreateTransient(Width, Height, PF_A32B32G32R32F);
	if (!RuntimeTexture)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create transient texture"));
		return;
	}

	RuntimeTexture->MipGenSettings = TMGS_NoMipmaps;
	RuntimeTexture->SRGB = false;
	RuntimeTexture->CompressionSettings = TC_Default; // no special compression
	RuntimeTexture->AddToRoot(); // optional: prevent GC while in use
	RuntimeTexture->UpdateResource(); // create GPU resource

	// Prepare CPU-side data as floats (RGBA32F => 4 floats per texel)
	const int32 NumTexels = Width * Height;
	const int32 NumFloats = NumTexels * 4; // 4 channels
	const int32 DataSizeBytes = NumFloats * sizeof(float);

	// Allocate raw byte buffer (will be freed after upload)
	uint8* RawData = static_cast<uint8*>(FMemory::Malloc(DataSizeBytes));
	// Ensure zeroed (optional)
	FMemory::Memzero(RawData, DataSizeBytes);

	// Fill per-texel float RGBA (we'll store position.xyz in RGBA.x/y/z and leave A = 0;
	// row 1 will store tangent.xyz)
	// We'll use float32 direct storage (no normalization), so shader reads raw values.
	float* FloatPtr = reinterpret_cast<float*>(RawData);

	for (int32 x = 0; x < Width; ++x)
	{
		// Row 0: Position
		FVector Pos = SplineComp->GetLocationAtSplinePoint(x, ESplineCoordinateSpace::Local);
		FVector Tang = SplineComp->GetTangentAtSplinePoint(x, ESplineCoordinateSpace::Local);

		// Texel index for row 0
		int32 texelIndex0 = (0 * Width) + x;
		FloatPtr[texelIndex0 * 4 + 0] = Pos.X;
		FloatPtr[texelIndex0 * 4 + 1] = Pos.Y;
		FloatPtr[texelIndex0 * 4 + 2] = Pos.Z;
		FloatPtr[texelIndex0 * 4 + 3] = 0.0f;

		// Texel index for row 1 (tangent)
		int32 texelIndex1 = (1 * Width) + x;
		FloatPtr[texelIndex1 * 4 + 0] = Tang.X;
		FloatPtr[texelIndex1 * 4 + 1] = Tang.Y;
		FloatPtr[texelIndex1 * 4 + 2] = Tang.Z;
		FloatPtr[texelIndex1 * 4 + 3] = 0.0f;
	}

	// Setup update region
	FUpdateTextureRegion2D Region(0, 0, 0, 0, Width, Height);

	// Pitch = bytes per row
	const uint32 SrcPitch = Width * 4 * sizeof(float); // bytes per row
	const uint32 SrcBpp = 4 * sizeof(float);

	UpdateTextureRegions(RuntimeTexture, 0, 1, &Region, SrcPitch, SrcBpp, RawData, true);

	// Create dynamic material instance from HISM's first material (ensure mesh has material slot 0)
	if (HISM)
	{
		UMaterialInterface* BaseMat = HISM->GetMaterial(0);
		if (BaseMat)
		{
			DynamicMID = UMaterialInstanceDynamic::Create(BaseMat, this);
			if (DynamicMID && RuntimeTexture)
			{
				DynamicMID->SetTextureParameterValue(TEXT("SplineDataTex"), RuntimeTexture);
				HISM->SetMaterial(0, DynamicMID);
			}
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Built spline texture: %d x %d"), Width, Height);
}

void AActor_FishClowds::UpdateTextureRegions(
	UTexture2D* Texture,
	int32 MipIndex,
	uint32 NumRegions,
	FUpdateTextureRegion2D* Regions,
	uint32 SrcPitch,
	uint32 SrcBpp,
	uint8* SrcData,
	bool bFreeData
)
{
	if (!Texture || !SrcData || NumRegions == 0)
	{
		if (bFreeData && SrcData)
		{
			FMemory::Free(SrcData);
		}
		return;
	}

	Texture->UpdateResource();

	struct FUpdateTextureRegionsData
	{
		UTexture2D* Texture;
		int32 MipIndex;
		uint32 NumRegions;
		FUpdateTextureRegion2D* Regions; // 소유 포인터 (힙)
		uint32 SrcPitch;
		uint32 SrcBpp;
		uint8* SrcData; // 소유 포인터 (힙)
	};

	// Regions 배열을 힙에 복사 (안전하게 렌더 스레드로 전달하기 위해)
	FUpdateTextureRegion2D* RegionsCopy = static_cast<FUpdateTextureRegion2D*>(FMemory::Malloc(sizeof(FUpdateTextureRegion2D) * NumRegions));
	FMemory::Memcpy(RegionsCopy, Regions, sizeof(FUpdateTextureRegion2D) * NumRegions);

	FUpdateTextureRegionsData* RegionData = new FUpdateTextureRegionsData{
		Texture, MipIndex, NumRegions, RegionsCopy, SrcPitch, SrcBpp, SrcData
	};

	ENQUEUE_RENDER_COMMAND(UpdateTextureRegionsData)(
		[RegionData, bFreeData](FRHICommandListImmediate& RHICmdList)
		{
			UTexture2D* Texture = RegionData->Texture;
			FTexture2DRHIRef TextureRefDeprecated; // 구버전 호환형(예시)
			// 새로운 API 사용: GetTextureRHI()
			FTextureRHIRef TextureRHI = Texture->GetResource()->GetTextureRHI();
			if (!TextureRHI)
			{
				UE_LOG(LogTemp, Error, TEXT("TextureRHI is null in render thread"));
				if (RegionData->Regions) FMemory::Free(RegionData->Regions);
				if (bFreeData && RegionData->SrcData) FMemory::Free(RegionData->SrcData);
				delete RegionData;
				return;
			}

			for (uint32 RegionIndex = 0; RegionIndex < RegionData->NumRegions; ++RegionIndex)
			{
				FUpdateTextureRegion2D* Region = &RegionData->Regions[RegionIndex];

				// SrcPtr 계산 (연속된 데이터로 가정)
				uint8* SrcPtr = RegionData->SrcData + RegionIndex * RegionData->SrcPitch * Region->Height;

				// RHIUpdateTexture2D 호출 (통합 RHI 타입 허용)
				RHIUpdateTexture2D(
					static_cast<FRHITexture2D*>(TextureRHI.GetReference()), // 일부 플랫폼/헤더에서 이 캐스트를 사용
					RegionData->MipIndex,
					*Region,
					RegionData->SrcPitch,
					SrcPtr
				);
			}

			// 할당 해제
			if (RegionData->Regions) FMemory::Free(RegionData->Regions);
			if (bFreeData && RegionData->SrcData) FMemory::Free(RegionData->SrcData);
			delete RegionData;
		}
		);
}
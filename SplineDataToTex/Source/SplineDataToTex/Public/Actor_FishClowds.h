#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_FishClowds.generated.h"

class USplineComponent;
class UInstancedStaticMeshComponent;
class UTexture2D;
class UMaterialInstanceDynamic;
class UHierarchicalInstancedStaticMeshComponent;

UCLASS()
class AActor_FishClowds : public AActor
{
    GENERATED_BODY()

public:
    AActor_FishClowds();

protected:
    virtual void BeginPlay() override;
    virtual void OnConstruction(const FTransform& Transform) override;

public:
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    USplineComponent* SplineComp;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    UInstancedStaticMeshComponent* ISM;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    UHierarchicalInstancedStaticMeshComponent* HISM;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 ISMCount = 100;

    UPROPERTY()
    UTexture2D* RuntimeTexture;

    UPROPERTY()
    UMaterialInstanceDynamic* DynamicMID;

    void SetInstanceCount(const int TargetCount);
    void BuildSplineTexture();

    // Helper to upload texture regions safely (RHI enqueue)
    void UpdateTextureRegions(
        UTexture2D* Texture,
        int32 MipIndex,
        uint32 NumRegions,
        FUpdateTextureRegion2D* Regions,
        uint32 SrcPitch,
        uint32 SrcBpp,
        uint8* SrcData,
        bool bFreeData = true
    );
};

// Copyright Epic Games, Inc. All Rights Reserved.

#include "DawSystemEditorModeToolkit.h"
#include "DawSystemEditorMode.h"
#include "Engine/Selection.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "EditorModeManager.h"

// 추가: OnScreen 메시지 출력을 위한 헤더
#include "Engine/Engine.h" // <-- 새로 추가 (GEngine 사용을 위해)

#define LOCTEXT_NAMESPACE "DawSystemEditorModeToolkit"

FDawSystemEditorModeToolkit::FDawSystemEditorModeToolkit()
{
}

void FDawSystemEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode)
{
	FModeToolkit::Init(InitToolkitHost, InOwningMode);
}

void FDawSystemEditorModeToolkit::GetToolPaletteNames(TArray<FName>& PaletteNames) const
{
	PaletteNames.Add(NAME_Default);
}

FName FDawSystemEditorModeToolkit::GetToolkitFName() const
{
	return FName("DawSystemEditorMode");
}

FText FDawSystemEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("DisplayName", "DawSystemEditorMode Toolkit");
}

// 추가: GetInlineContent 구현 (커스텀 UI 빌드)
TSharedPtr<SWidget> FDawSystemEditorModeToolkit::GetInlineContent() const
{
	if (!InlineContent.IsValid())
	{
		// 기본 DetailsView나 팔레트를 포함한 VerticalBox로 UI 구성
		InlineContent = SNew(SVerticalBox)

			// 기존 툴 팔레트나 DetailsView 슬롯 (기본 툴킷 기능 유지)
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				// 여기에 기존 툴 팔레트나 DetailsView를 추가할 수 있음 (예: FModeToolkit::GetInlineContent())
				SNew(STextBlock).Text(LOCTEXT("Placeholder", "Existing Toolkit Content")) // 플레이스홀더, 실제로는 DetailsView로 교체
			]

			// 추가: Hello 버튼 슬롯
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(5.0f) // 여백 추가
			[
				SNew(SButton)
					.Text(LOCTEXT("HelloButton", "Say Hello")) // 버튼 텍스트
					.OnClicked(this, &FDawSystemEditorModeToolkit::OnHelloButtonClicked) // 클릭 핸들러 연결
			];
	}

	return InlineContent.ToSharedRef();
}

// 추가: 버튼 클릭 핸들러 구현
FReply FDawSystemEditorModeToolkit::OnHelloButtonClicked() const
{
	FGlobalTabmanager::Get()->TryInvokeTab(DockableTabId);  // ← 새로 추가: 창 열기 (이미 열려 있으면 포커스)

	return FReply::Handled(); // 이벤트 처리 완료
}

// 추가: 탭 스포너 함수 구현 (파일 끝부분에 추가)
TSharedRef<SDockTab> FDawSystemEditorModeToolkit::SpawnDockableTab(const FSpawnTabArgs& Args)
{
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)  // ← 핵심: NomadTab으로 설정하면 dock 가능
		.Label(LOCTEXT("TabLabel", "My Dockable Window"))
		[
			SNew(SVerticalBox)  // 창 콘텐츠 예시 (커스텀 가능)
				+ SVerticalBox::Slot().AutoHeight()
				[
					SNew(STextBlock).Text(LOCTEXT("Content", "Hello, this is a dockable window!"))
				]
				// 여기에 추가 위젯 (UMG, 버튼 등) 삽입 가능
		];
}

#undef LOCTEXT_NAMESPACE
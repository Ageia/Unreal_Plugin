// Copyright Epic Games, Inc. All Rights Reserved.

#include "DawSystemModule.h"
#include "DawSystemEditorModeCommands.h"

#define LOCTEXT_NAMESPACE "DawSystemModule"

// 추가: static Tab ID 초기화 (파일 상단에)
FName FDawSystemModule::DockableTabId = FName("MyDockableTab");  // ← 새로 추가

void FDawSystemModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

    FDawSystemEditorModeCommands::Register();

    // 추가: Dockable 탭 스포너 등록 (SetTooltip 제거)
    FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
        DockableTabId,
        FOnSpawnTab::CreateRaw(this, &FDawSystemModule::SpawnDockableTab)  // ← 모듈 클래스의 함수로 변경
    )
        .SetDisplayName(LOCTEXT("TabTitle", "My Dockable Window"))
        .SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Info"));  // 아이콘 옵션 (필요 없으면 제거)
}

void FDawSystemModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.

    FDawSystemEditorModeCommands::Unregister();

    // 추가: 탭 스포너 해제
    FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(DockableTabId);
}

// 추가: 탭 스포너 함수 구현 (파일 끝부분에)
TSharedRef<SDockTab> FDawSystemModule::SpawnDockableTab(const FSpawnTabArgs& Args)
{
    return SNew(SDockTab)
        .TabRole(ETabRole::NomadTab)  // ← 핵심: NomadTab으로 dock 가능
        .Label(LOCTEXT("TabLabel", "My Dockable Window"))
        [
            SNew(SVerticalBox)  // 창 콘텐츠 예시
                + SVerticalBox::Slot().AutoHeight()
                [
                    SNew(STextBlock).Text(LOCTEXT("Content", "Hello, this is a dockable window!"))
                ]
                // 추가 위젯 삽입 가능
        ];
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDawSystemModule, DawSystem)
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Toolkits/BaseToolkit.h"
#include "DawSystemEditorMode.h"

// 추가: Slate 관련 헤더 포함 (버튼 위젯 사용을 위해)
#include "Widgets/Input/SButton.h"  // <-- 새로 추가
#include "Widgets/Layout/SBorder.h" // <-- 새로 추가 (UI 레이아웃을 위해 옵션)
#include "Widgets/SCompoundWidget.h" // <-- 새로 추가

#include "SlateBasics.h"  // ← 새로 추가
#include "SlateExtras.h"  // ← 새로 추가
#include "LevelEditor.h"  // ← 새로 추가 (FLevelEditorModule)

/**
 * This FModeToolkit just creates a basic UI panel that allows various InteractiveTools to
 * be initialized, and a DetailsView used to show properties of the active Tool.
 */
class FDawSystemEditorModeToolkit : public FModeToolkit
{
public:
    FDawSystemEditorModeToolkit();

    /** FModeToolkit interface */
    virtual void Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode) override;
    virtual void GetToolPaletteNames(TArray<FName>& PaletteNames) const override;

    /** IToolkit interface */
    virtual FName GetToolkitFName() const override;
    virtual FText GetBaseToolkitName() const override;

    // 추가: 툴킷의 전체 UI를 반환하는 메서드 오버라이드 (커스텀 UI 빌드를 위해)
    virtual TSharedPtr<SWidget> GetInlineContent() const override;  // ← TSharedPtr로 변경

public:
    // 추가: 버튼 클릭 핸들러 메서드 선언
    FReply OnHelloButtonClicked() const; // <-- 새로 추가

    // 추가: UI 위젯 참조 (mutable로 선언하여 const 메서드에서 사용 가능)
    mutable TSharedPtr<SWidget> InlineContent; // <-- 새로 추가

    // 추가: Dockable 탭 관련
    FName DockableTabId = FName("MyDockableTab");  // ← 새로 추가: 탭 고유 ID

    TSharedRef<SDockTab> SpawnDockableTab(const FSpawnTabArgs& Args);  // ← 새로 추가: 탭 스포너 함수 선언
};
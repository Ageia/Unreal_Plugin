// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

// 추가: Slate 관련 헤더 (dock 탭을 위해)
#include "SlateBasics.h"  // ← 새로 추가
#include "SlateExtras.h"  // ← 새로 추가
#include "LevelEditor.h"  // ← 새로 추가 (FLevelEditorModule)

/**
 * This is the module definition for the editor mode. You can implement custom functionality
 * as your plugin module starts up and shuts down. See IModuleInterface for more extensibility options.
 */
class FDawSystemModule : public IModuleInterface
{
public:

    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    // 추가: Dockable 탭 관련 (모듈 클래스에 이동)
    static FName DockableTabId;  // ← 새로 추가: static으로 정의

    TSharedRef<SDockTab> SpawnDockableTab(const FSpawnTabArgs& Args);  // ← 새로 추가: public 함수
};
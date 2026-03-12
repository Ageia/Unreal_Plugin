// Copyright Epic Games, Inc. All Rights Reserved.

#include "DawSystemEditorMode.h"
#include "DawSystemEditorModeToolkit.h"
#include "EdModeInteractiveToolsContext.h"
#include "InteractiveToolManager.h"
#include "DawSystemEditorModeCommands.h"
#include "Modules/ModuleManager.h"


//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
// AddYourTool Step 1 - include the header file for your Tools here
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
#include "Tools/DawSystemSimpleTool.h"
#include "Tools/DawSystemInteractiveTool.h"

// step 2: register a ToolBuilder in FDawSystemEditorMode::Enter() below


#define LOCTEXT_NAMESPACE "DawSystemEditorMode"

const FEditorModeID UDawSystemEditorMode::EM_DawSystemEditorModeId = TEXT("EM_DawSystemEditorMode");

FString UDawSystemEditorMode::SimpleToolName = TEXT("DawSystem_ActorInfoTool");
FString UDawSystemEditorMode::InteractiveToolName = TEXT("DawSystem_MeasureDistanceTool");


UDawSystemEditorMode::UDawSystemEditorMode()
{
	FModuleManager::Get().LoadModule("EditorStyle");

	// appearance and icon in the editing mode ribbon can be customized here
	Info = FEditorModeInfo(UDawSystemEditorMode::EM_DawSystemEditorModeId,
		LOCTEXT("ModeName", "DawSystem"),
		FSlateIcon(),
		true);
}


UDawSystemEditorMode::~UDawSystemEditorMode()
{
}


void UDawSystemEditorMode::ActorSelectionChangeNotify()
{
}

void UDawSystemEditorMode::Enter()
{
	UEdMode::Enter();

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// AddYourTool Step 2 - register the ToolBuilders for your Tools here.
	// The string name you pass to the ToolManager is used to select/activate your ToolBuilder later.
	//////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////// 
	const FDawSystemEditorModeCommands& SampleToolCommands = FDawSystemEditorModeCommands::Get();

	RegisterTool(SampleToolCommands.SimpleTool, SimpleToolName, NewObject<UDawSystemSimpleToolBuilder>(this));
	RegisterTool(SampleToolCommands.InteractiveTool, InteractiveToolName, NewObject<UDawSystemInteractiveToolBuilder>(this));

	// active tool type is not relevant here, we just set to default
	GetToolManager()->SelectActiveToolType(EToolSide::Left, SimpleToolName);
}

void UDawSystemEditorMode::CreateToolkit()
{
	Toolkit = MakeShareable(new FDawSystemEditorModeToolkit);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> UDawSystemEditorMode::GetModeCommands() const
{
	return FDawSystemEditorModeCommands::Get().GetCommands();
}

#undef LOCTEXT_NAMESPACE

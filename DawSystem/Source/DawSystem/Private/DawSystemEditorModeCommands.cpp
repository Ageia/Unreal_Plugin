// Copyright Epic Games, Inc. All Rights Reserved.

#include "DawSystemEditorModeCommands.h"
#include "DawSystemEditorMode.h"
#include "EditorStyleSet.h"

#define LOCTEXT_NAMESPACE "DawSystemEditorModeCommands"

FDawSystemEditorModeCommands::FDawSystemEditorModeCommands()
	: TCommands<FDawSystemEditorModeCommands>("DawSystemEditorMode",
		NSLOCTEXT("DawSystemEditorMode", "DawSystemEditorModeCommands", "DawSystem Editor Mode"),
		NAME_None,
		FAppStyle::GetAppStyleSetName())
{
}

void FDawSystemEditorModeCommands::RegisterCommands()
{
	TArray <TSharedPtr<FUICommandInfo>>& ToolCommands = Commands.FindOrAdd(NAME_Default);

	UI_COMMAND(SimpleTool, "Show Actor Info", "Opens message box with info about a clicked actor", EUserInterfaceActionType::Button, FInputChord());
	ToolCommands.Add(SimpleTool);

	UI_COMMAND(InteractiveTool, "Measure Distance", "Measures distance between 2 points (click to set origin, shift-click to set end point)", EUserInterfaceActionType::ToggleButton, FInputChord());
	ToolCommands.Add(InteractiveTool);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> FDawSystemEditorModeCommands::GetCommands()
{
	return FDawSystemEditorModeCommands::Get().Commands;
}

#undef LOCTEXT_NAMESPACE

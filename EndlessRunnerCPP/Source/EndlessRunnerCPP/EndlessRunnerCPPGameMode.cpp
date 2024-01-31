// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessRunnerCPPGameMode.h"
#include "EndlessRunnerCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEndlessRunnerCPPGameMode::AEndlessRunnerCPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

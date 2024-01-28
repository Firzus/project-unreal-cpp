// Copyright Epic Games, Inc. All Rights Reserved.

#include "SampleActorProjectGameMode.h"
#include "SampleActorProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASampleActorProjectGameMode::ASampleActorProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RunCharacter.h"
#include "RunCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNERCPP_API ARunCharacterController : public APlayerController
{
	GENERATED_BODY()

protected:
	ARunCharacter* ControlledRunCharacter;

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void MoveRight(float AxisValue);
};

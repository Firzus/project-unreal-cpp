// Fill out your copyright notice in the Description page of Project Settings.

#include "RunCharacterController.h"

void ARunCharacterController::BeginPlay()
{
	Super::BeginPlay();
	
	APawn* ControlledPawn = GetPawn();
	
	if (ControlledPawn != nullptr)
	{
		ControlledRunCharacter = Cast<ARunCharacter>(ControlledPawn);
	}
}

void ARunCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	InputComponent->BindAxis("MoveRight", this, &ARunCharacterController::MoveRight);
}

void ARunCharacterController::MoveRight(float AxisValue)
{
	if (ControlledRunCharacter)
	{
		FVector Direction = ControlledRunCharacter->GetActorRightVector();
		ControlledRunCharacter->AddMovementInput(Direction, AxisValue);
	}
}
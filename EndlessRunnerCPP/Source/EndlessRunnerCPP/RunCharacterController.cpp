// Fill out your copyright notice in the Description page of Project Settings.


#include "RunCharacterController.h"

void ARunCharacterController::BeginPlay()
{
	Super::BeginPlay();
	
	APawn* ControlledPawn = GetPawn();
	
	if (ControlledPawn != nullptr)
	{
		ControlledRunCharacter = Cast<ARunCharacter>(ControlledPawn);
		if (ControlledRunCharacter != nullptr)
		{
			// Le Pawn est un RunCharacter, et vous pouvez maintenant appeler des fonctions dessus
		}
		else
		{
			// Le Pawn n'est pas un RunCharacter, gérez cette situation comme nécessaire
		}
	}
}

void ARunCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	InputComponent->BindAxis("MoveForward", this, &ARunCharacterController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ARunCharacterController::MoveRight);
}

void ARunCharacterController::MoveForward(float AxisValue)
{
	if (ControlledRunCharacter)
	{
		FVector Direction = ControlledRunCharacter->GetActorForwardVector();
		ControlledRunCharacter->AddMovementInput(Direction, AxisValue);
	}
}

void ARunCharacterController::MoveRight(float AxisValue)
{
	if (ControlledRunCharacter)
	{
		FVector Direction = ControlledRunCharacter->GetActorRightVector();
		ControlledRunCharacter->AddMovementInput(Direction, AxisValue);
	}
}
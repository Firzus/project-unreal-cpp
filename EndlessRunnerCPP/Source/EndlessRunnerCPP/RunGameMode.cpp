// Fill out your copyright notice in the Description page of Project Settings.


#include "RunGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "RunCharacter.h"

ARunGameMode::ARunGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARunGameMode::BeginPlay()
{
	Super::BeginPlay();

	ARunCharacter* PlayerCharacter = Cast<ARunCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (PlayerCharacter)
	{
		PlayerCharacter->OnCharacterDeath.AddDynamic(this, &ARunGameMode::HandlePlayerDeath);
	}
}

void ARunGameMode::HandlePlayerDeath()
{
	FTimerHandle UnusedHandle;
	GetWorld()->GetTimerManager().SetTimer(UnusedHandle, this, &ARunGameMode::RestartLevel, 3.0f, false);
}

void ARunGameMode::RestartLevel()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}
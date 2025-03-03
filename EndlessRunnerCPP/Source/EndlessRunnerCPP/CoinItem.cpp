﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinItem.h"

#include "RunCharacter.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACoinItem::ACoinItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACoinItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACoinItem::OnHit(AActor* OtherActor)
{
	Super::OnHit(OtherActor);

	ARunCharacter* Player = Cast<ARunCharacter>(OtherActor);
	if (Player)
	{
		Player->AddCoins(CoinsValue);
	}

	if (CollectSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, CollectSound, GetActorLocation());
	}

	// Détruire l'objet CoinItem
	Destroy();
}


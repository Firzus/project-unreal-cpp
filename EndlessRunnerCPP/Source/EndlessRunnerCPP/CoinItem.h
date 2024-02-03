// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Sound/SoundBase.h"
#include "CoinItem.generated.h"

UCLASS()
class ENDLESSRUNNERCPP_API ACoinItem : public AItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACoinItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Surcharge de la méthode OnHit
	virtual void OnHit(AActor* OtherActor) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sound")
	USoundBase* CollectSound;

	UPROPERTY(EditDefaultsOnly, Category = "Coins")
	int32 CoinsValue = 1;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

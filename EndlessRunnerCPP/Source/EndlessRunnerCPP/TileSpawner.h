// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorTile.h"
#include "TileSpawner.generated.h"

UCLASS()
class ENDLESSRUNNERCPP_API ATileSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATileSpawner();

	void SpawnNextTile();

	UFUNCTION()
	void HandleTileExited(AFloorTile* Tile);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AActor> TileClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	int32 InitialTileCount;

	FVector LastAttachPoint;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

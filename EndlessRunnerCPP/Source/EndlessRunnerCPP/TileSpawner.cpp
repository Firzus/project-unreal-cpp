// Fill out your copyright notice in the Description page of Project Settings.


#include "TileSpawner.h"
#include "FloorTile.h"


// Sets default values
ATileSpawner::ATileSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	InitialTileCount = 6;
}

void ATileSpawner::SpawnNextTile()
{
	if (TileClass != nullptr)
	{
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(LastAttachPoint);
        
		AFloorTile* NewTile = GetWorld()->SpawnActor<AFloorTile>(TileClass, SpawnTransform);

		if (NewTile != nullptr)
		{
			LastAttachPoint = NewTile->GetAttachTransform().GetLocation();
			
			NewTile->OnTileExited.AddDynamic(this, &ATileSpawner::HandleTileExited);
		}
	}
}

void ATileSpawner::HandleTileExited(AFloorTile* Tile)
{
	SpawnNextTile();
}

// Called when the game starts or when spawned
void ATileSpawner::BeginPlay()
{
	Super::BeginPlay();

	for(int32 i = 0; i < InitialTileCount; ++i)
	{
		SpawnNextTile();
	}
}

// Called every frame
void ATileSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


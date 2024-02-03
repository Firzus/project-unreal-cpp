// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// Components
#include "Components/SceneComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

#include "FloorTile.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTileExitedSignature, AFloorTile*, Tile);

UCLASS()
class ENDLESSRUNNERCPP_API AFloorTile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFloorTile();

	void ScheduleDestruction();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void DestroyTile();

	UFUNCTION()
	void SpawnObstacle();

	UFUNCTION()
	void SpawnItem();

	UFUNCTION()
	void Spawn();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USceneComponent* RootScene;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* Floor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* WallLeft;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* WallRight;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UArrowComponent* DirectionIndicator;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Collision")
	UBoxComponent* ExitTrigger;
	
	UPROPERTY(BlueprintAssignable, Category="Tile")
	FOnTileExitedSignature OnTileExited;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UBoxComponent* SpawnZoneObstacle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UBoxComponent* SpawnZoneItem;
	
	UPROPERTY(EditAnywhere, Category="Spawning")
	TArray<TSubclassOf<AActor>> ObstacleClasses;

	UPROPERTY(EditAnywhere, Category="Spawning")
	TArray<TSubclassOf<AActor>> ItemClasses;

	// Chance de spawn pour les obstacles et les pickups
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float ObstacleSpawnChance = 60.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float PickupSpawnChance = 30.0f;

	// Nombre maximum de pickups à générer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	int32 MaxPickupCount = 3;
	
	FTransform GetAttachTransform() const;

private:
	UFUNCTION()
	void OnExitTriggerOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

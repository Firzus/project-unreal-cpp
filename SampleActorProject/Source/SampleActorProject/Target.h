// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class SAMPLEACTORPROJECT_API ATarget : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveTarget(float DeltaTime);
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementAmplitude;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementFrequency;

	// Pour garder la trace de l'animation sinusoïdale
	float RunningTime;

	// Direction de mouvement
	FVector MovementDirection;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;
};

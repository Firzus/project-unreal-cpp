﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "TreeObstacle.generated.h"

UCLASS()
class ENDLESSRUNNERCPP_API ATreeObstacle : public AObstacle
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATreeObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

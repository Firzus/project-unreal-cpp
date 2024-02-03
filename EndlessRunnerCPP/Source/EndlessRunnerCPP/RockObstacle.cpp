// Fill out your copyright notice in the Description page of Project Settings.


#include "RockObstacle.h"


// Sets default values
ARockObstacle::ARockObstacle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARockObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARockObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"
#include "SampleGameMode.h"
#include "Components/StaticMeshComponent.h"



// Sets default values
ATarget::ATarget()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	// Set up the on hit event
	StaticMesh->OnComponentHit.AddDynamic(this, &ATarget::OnHit);
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATarget::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != nullptr && OtherActor != this && OtherComp != nullptr)
	{
		ASampleGameMode* GameMode = Cast<ASampleGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode != nullptr)
		{
			GameMode->IncreasePoints(1);
		}

		Destroy();
	}
}
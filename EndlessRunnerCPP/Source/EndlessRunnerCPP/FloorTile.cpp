// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorTile.h"

#include "Kismet/KismetMathLibrary.h"


// Sets default values
AFloorTile::AFloorTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;
	
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeComponent"));
	Floor->SetupAttachment(RootScene); 
	
	Floor->SetRelativeLocation(FVector(500.0f, 0.0f, 0.0f));
	Floor->SetRelativeScale3D(FVector(10.f, 10.f, 0.1f));
	
	WallLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallLeft"));
	WallLeft->SetupAttachment(RootScene);
	WallLeft->SetRelativeScale3D(FVector(10.f, 0.1f, 2.f));
	WallLeft->SetRelativeLocation(FVector(500, -500, 0)); 
	
	WallRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallRight"));
	WallRight->SetupAttachment(RootScene);
	WallRight->SetRelativeScale3D(FVector(10.f, 0.1f, 2.f));
	WallRight->SetRelativeLocation(FVector(500, 500, 0));

	DirectionIndicator = CreateDefaultSubobject<UArrowComponent>(TEXT("DirectionIndicator"));
	DirectionIndicator->SetupAttachment(RootScene);
	DirectionIndicator->SetRelativeLocation(FVector(1000, 0, 0));

	ExitTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	ExitTrigger->SetupAttachment(RootScene);
	ExitTrigger->SetBoxExtent(FVector(10, 500, 100));
	ExitTrigger->SetRelativeLocation(FVector(1010, 0, 100));

	ExitTrigger->OnComponentBeginOverlap.AddDynamic(this, &AFloorTile::OnExitTriggerOverlap);
	ExitTrigger->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));

	SpawnZone = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnZone"));
	SpawnZone->SetupAttachment(RootScene);
	SpawnZone->SetRelativeLocation(FVector(800, 0, 0));
	SpawnZone->SetBoxExtent(FVector(1, 300, 1));
}

void AFloorTile::ScheduleDestruction()
{
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AFloorTile::DestroyTile, 2.0f, false);
}

// Called when the game starts or when spawned
void AFloorTile::BeginPlay()
{
	Super::BeginPlay();

	SpawnObstacle();
}

void AFloorTile::DestroyTile()
{
	Destroy();
}

// Called every frame
void AFloorTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFloorTile::OnExitTriggerOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (APawn* Pawn = Cast<APawn>(OtherActor))
	{
		OnTileExited.Broadcast(this);
		ScheduleDestruction();
	}
}

FTransform AFloorTile::GetAttachTransform() const
{
	return DirectionIndicator->GetComponentTransform();
}

void AFloorTile::SpawnObstacle() // ou ATileSpawner::SpawnObstacle
{
	if (ObstacleClasses.Num() > 0)
	{
		// Choisir aléatoirement une classe d'obstacle
		TSubclassOf<AActor> SelectedObstacleClass = ObstacleClasses[FMath::RandRange(0, ObstacleClasses.Num() - 1)];

		FVector BoxExtent = SpawnZone->GetScaledBoxExtent();
		FVector Origin = SpawnZone->GetComponentLocation();
		FVector SpawnPoint = UKismetMathLibrary::RandomPointInBoundingBox(Origin, BoxExtent);

		FTransform SpawnTransform(FRotator::ZeroRotator, SpawnPoint);
		AActor* SpawnedObstacle = GetWorld()->SpawnActor<AActor>(SelectedObstacleClass, SpawnTransform);

		if (SpawnedObstacle != nullptr)
		{
			SpawnedObstacle->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
		}
	}
}

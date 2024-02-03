// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

#include "RunCharacter.h"


// Sets default values
AItem::AItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// create the root component
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	
	// create the static mesh component
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	ItemMesh->SetupAttachment(Root);
	ItemMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ItemMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	ItemMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	ItemMesh->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnComponentBeginOverlap);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItem::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->IsA<ARunCharacter>())
	{
		OnHit(OtherActor);
	}
}

void AItem::OnHit(AActor* OtherActor)
{
	// La logique par défaut peut être de détruire l'item ou de déclencher un effet visuel/sonore
	// Les classes dérivées peuvent surcharger cette fonction pour implémenter un comportement spécifique
}

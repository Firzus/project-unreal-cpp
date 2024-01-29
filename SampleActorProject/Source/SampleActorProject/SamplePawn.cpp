// Fill out your copyright notice in the Description page of Project Settings.


#include "SamplePawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
// Sets default values
ASamplePawn::ASamplePawn()
{
	// Set this pawn to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
	// Initialize StaticMeshComponent
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	// Initialize SpringArmComponent first
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	// Initialize CameraComponent and attach it to the SpringArm
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArm);

	// Initialize FloatingPawnMovement
	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingMovement"));
}

// Called when the game starts or when spawned
void ASamplePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASamplePawn::MoveForward(float Value)
{
	if (FloatingMovement)
	{
		FloatingMovement->AddInputVector(GetActorForwardVector() * Value);
	}
}

void ASamplePawn::MoveRight(float Value)
{
	if (FloatingMovement)
	{
		FloatingMovement->AddInputVector(GetActorRightVector() * Value);
	}
}

void ASamplePawn::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ASamplePawn::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

// Called every frame
void ASamplePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASamplePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASamplePawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASamplePawn::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn", this, &ASamplePawn::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ASamplePawn::LookUp);
}


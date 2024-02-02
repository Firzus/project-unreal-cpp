// Fill out your copyright notice in the Description page of Project Settings.


#include "RunCharacter.h"


// Sets default values
ARunCharacter::ARunCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialiser le Spring Arm
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArm->SetupAttachment(RootComponent);
	CameraSpringArm->TargetArmLength = 300.0f; // La longueur du Spring Arm
	CameraSpringArm->bUsePawnControlRotation = true; // La caméra suit la rotation du joueur
	CameraSpringArm->bDoCollisionTest = false; // Désactiver le test de collision
	CameraSpringArm->SocketOffset = FVector(0.0f, 0.0f, 100.0f); // Décaler légèrement en hauteur

	// Initialiser la caméra et l'attacher au Spring Arm
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(CameraSpringArm, USpringArmComponent::SocketName);

	ForwardSpeed = 1000.0f;
}

// Called when the game starts or when spawned
void ARunCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARunCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector Direction = GetActorForwardVector();
	AddMovementInput(Direction, ForwardSpeed * DeltaTime);
}

// Called to bind functionality to input
void ARunCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


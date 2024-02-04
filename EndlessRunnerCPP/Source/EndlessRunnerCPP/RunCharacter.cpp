// Fill out your copyright notice in the Description page of Project Settings.


#include "RunCharacter.h"

#include "RunCharacterController.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ARunCharacter::ARunCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialiser le Spring Arm
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArm->SetupAttachment(RootComponent);
	CameraSpringArm->TargetArmLength = 300.0f;
	CameraSpringArm->bUsePawnControlRotation = true;
	CameraSpringArm->bDoCollisionTest = false; 
	CameraSpringArm->SocketOffset = FVector(0.0f, 0.0f, 100.0f); 

	// Initialiser la caméra et l'attacher au Spring Arm
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(CameraSpringArm, USpringArmComponent::SocketName);

	ForwardSpeed = 100.0f;
	bIsDead = false;
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

void ARunCharacter::Die()
{
	if (!bIsDead)
	{
		bIsDead = true;

		OnCharacterDeath.Broadcast();

        ARunCharacterController* RunCharacterController = Cast<ARunCharacterController>(GetController());
        if (RunCharacterController)
        {
            RunCharacterController->DisableInput(RunCharacterController);
        }

		ForwardSpeed = 0.0f;

		// Jouer l'effet de particules
		UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionEffect, GetActorLocation());

		// Jouer l'effet de son
		UGameplayStatics::PlaySoundAtLocation(this, ExplosionSound, GetActorLocation());
	}
}

void ARunCharacter::AddCoins(int32 NumberOfCoins)
{
	CoinsCollected += NumberOfCoins;
}

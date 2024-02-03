// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "RunCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterDeath);

UCLASS()
class ENDLESSRUNNERCPP_API ARunCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARunCharacter();

	// Événement pour la mort du personnage
	UPROPERTY(BlueprintAssignable, Category = "Event")
	FOnCharacterDeath OnCharacterDeath;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraSpringArm;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float ForwardSpeed;

	UPROPERTY(EditAnywhere, Category="Effects")
	UParticleSystem* ExplosionEffect;

	UPROPERTY(EditAnywhere, Category="Sound")
	USoundBase* ExplosionSound;

	UPROPERTY(VisibleAnywhere, Category = "Coins")
	int32 CoinsCollected = 0;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category="Character")
	void Die();

	void AddCoins(int32 NumberOfCoins);
	
private:
	bool bIsDead;
};

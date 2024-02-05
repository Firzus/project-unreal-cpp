#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SampleGameMode.generated.h"

UCLASS()
class SAMPLEACTORPROJECT_API ASampleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASampleGameMode();

	// Variable pour stocker les points pour gagner
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	int32 PointsToWin;

	// Variable pour stocker les points actuels
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	int32 CurrentPoints;

	// Fonction pour augmenter les points et déterminer la condition de victoire
	UFUNCTION(BlueprintCallable, Category = "Score")
	void IncreasePoints(int32 Amount);

	// Événements BlueprintImplementable pour augmenter les points et la condition de victoire
	UFUNCTION(BlueprintImplementableEvent, Category = "Score")
	void OnPointsIncreased(int32 NewTotalPoints);

	UFUNCTION(BlueprintImplementableEvent, Category = "Score")
	void OnWinConditionMet();
};

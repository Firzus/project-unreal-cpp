// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleGameMode.h"

ASampleGameMode::ASampleGameMode()
{
    PointsToWin = 5;
    CurrentPoints = 0;
}

void ASampleGameMode::IncreasePoints(int32 Amount)
{
    CurrentPoints += Amount;
    OnPointsIncreased(CurrentPoints);
    
    if (CurrentPoints >= PointsToWin)
    {
        OnWinConditionMet();
    }
}
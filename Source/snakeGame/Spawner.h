// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class AFood;
class ASpeedUpBonus;
class ASpeedDownBonus;

UCLASS()
class SNAKEGAME_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFood> FoodClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpeedUpBonus> SpeedUpBonusClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpeedDownBonus> SpeedDownBonusClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpeedUpBonus> SpeedUpBonusClassToFind;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpeedDownBonus> SpeedDownBonusClassToFind;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFood> FoodClassToFind;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnFood(int FoodNum = 1);

	UFUNCTION()
	void SpawnSpeedUpBonus();

	UFUNCTION()
	void SpawnSpeedDownBonus();

	UFUNCTION()
	void CheckNeedSpawn();
};

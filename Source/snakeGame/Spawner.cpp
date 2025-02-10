// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "Food.h"
#include "SpeedUpBonus.h"
#include "SpeedDownBonus.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickInterval(2);
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckNeedSpawn();
}

void ASpawner::SpawnFood(int FoodNum)
{
	for (int i = 0; i < FoodNum; ++i) {
		int32 minX = -450;
		int32 maxX = 440;
		int32 minY = -460;
		int32 maxY = 450;
		FVector NewLocation(FMath::RandRange(minX, maxX), FMath::RandRange(minY, maxY), 1);
		FTransform NewTransform(NewLocation);
		AFood* NewFoodElem = GetWorld()->SpawnActor<AFood>(FoodClass, NewTransform);
	}
}

void ASpawner::SpawnSpeedUpBonus()
{
	int32 minX = -450;
	int32 maxX = 440;
	int32 minY = -460;
	int32 maxY = 450;
	FVector NewLocation(FMath::RandRange(minX, maxX), FMath::RandRange(minY, maxY), 1);
	FTransform NewTransform(NewLocation);
	ASpeedUpBonus* NewSpeedUpBonusElem = GetWorld()->SpawnActor<ASpeedUpBonus>(SpeedUpBonusClass, NewTransform);
}

void ASpawner::SpawnSpeedDownBonus()
{
	int32 minX = -450;
	int32 maxX = 440;
	int32 minY = -460;
	int32 maxY = 450;
	FVector NewLocation(FMath::RandRange(minX, maxX), FMath::RandRange(minY, maxY), 1);
	FTransform NewTransform(NewLocation);
	ASpeedDownBonus* NewSpeedDownBonusElem = GetWorld()->SpawnActor<ASpeedDownBonus>(SpeedDownBonusClass, NewTransform);
}

void ASpawner::CheckNeedSpawn()
{
	TArray<AActor*> FoundFoodActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), FoodClassToFind, FoundFoodActors);
	if (FoundFoodActors.Num() < 4) {
		this->SpawnFood();
	}

	TArray<AActor*> FoundSpeedUpBonusActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpeedUpBonusClassToFind, FoundSpeedUpBonusActors);
	if (FoundSpeedUpBonusActors.Num() < 1) {
		this->SpawnSpeedUpBonus();
	}

	TArray<AActor*> FoundSpeedDownBonusActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpeedDownBonusClassToFind, FoundSpeedDownBonusActors);
	if (FoundSpeedDownBonusActors.Num() < 1) {
		this->SpawnSpeedDownBonus();
	}
}




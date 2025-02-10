// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "SpeedDownBonus.generated.h"

class ASpawner;
class UStaticMeshComponent;

UCLASS()
class SNAKEGAME_API ASpeedDownBonus : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpeedDownBonus();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Interacts with the snake head
	virtual void Interact(AActor* Interactor, bool bIsHead) override;

	// Checks if the spawned bonus is overlapping with other bonus elements, obstacles, food or snake tail and destroys this bonus if so
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};

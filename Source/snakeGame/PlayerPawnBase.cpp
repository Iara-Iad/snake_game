// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnBase.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "SnakeBase.h"
#include "Spawner.h"
#include "Components/InputComponent.h"

// Sets default values
APlayerPawnBase::APlayerPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	RootComponent = PawnCamera;
}

// Called when the game starts or when spawned
void APlayerPawnBase::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(-90, 0, 0));
	CreateSnakeActor();
	CreateSpawner();
}

// Called every frame
void APlayerPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawnBase::HandlePlayerVerticalInput);
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawnBase::HandlePlayerHorizontalInput);
}

void APlayerPawnBase::CreateSnakeActor()
{
	SnakeActor = GetWorld()->SpawnActor<ASnakeBase>(SnakeActorClass, FTransform());
}

void APlayerPawnBase::CreateSpawner()
{
	Spawner = GetWorld()->SpawnActor<ASpawner>(SpawnerClass, FTransform());
}

void APlayerPawnBase::HandlePlayerVerticalInput(float value)
{
	if (IsValid(SnakeActor)) {
		if (value > 0 && SnakeActor->LastMoveDirection != EMovementDirection::DOWN && SnakeActor->moved == true) {
			SnakeActor->LastMoveDirection = EMovementDirection::UP;
			SnakeActor->moved = false;
		}
		else if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::UP && SnakeActor->moved == true) {
			SnakeActor->LastMoveDirection = EMovementDirection::DOWN;
			SnakeActor->moved = false;
		}
	}
}

void APlayerPawnBase::HandlePlayerHorizontalInput(float value)
{
	if (IsValid(SnakeActor)) {
		if (value > 0 && SnakeActor->LastMoveDirection != EMovementDirection::LEFT && SnakeActor->moved == true) {
			SnakeActor->LastMoveDirection = EMovementDirection::RIGHT;
			SnakeActor->moved = false;
		}
		else if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::RIGHT && SnakeActor->moved == true) {
			SnakeActor->LastMoveDirection = EMovementDirection::LEFT;
			SnakeActor->moved = false;
		}
	}
}

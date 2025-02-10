// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "SnakeBase.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Overlap);

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AFood::OnBeginOverlap);
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Checks the interaction with the snake head
void AFood::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead) {
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake)) {
			Snake->AddSnakeElement();
			this->Destroy();
		}
	}
}


void AFood::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	this->Destroy();
}





// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedUpBonus.h"
#include "SnakeBase.h"

// Sets default values
ASpeedUpBonus::ASpeedUpBonus()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
}

// Called when the game starts or when spawned
void ASpeedUpBonus::BeginPlay()
{
	Super::BeginPlay();
	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpeedUpBonus::OnBeginOverlap);
}

// Called every frame
void ASpeedUpBonus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpeedUpBonus::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead) {
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake)) {
			if (Snake->GetActorTickInterval() > 0.2) {
				Snake->SetActorTickInterval(Snake->GetActorTickInterval() - 0.1);
				this->Destroy();
			}
		}
	}
}

void ASpeedUpBonus::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	this->Destroy();
}

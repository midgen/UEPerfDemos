// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PerfDemoSpawner.h"


// Sets default values
APerfDemoSpawner::APerfDemoSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void APerfDemoSpawner::BeginPlay()
{
	Super::BeginPlay();

	FVector SpawnLocation;
	for(int i = 0; i < SpawnCount ; ++i)
	{
		SpawnLocation.X = FMath::RandRange(-SpawnRange, SpawnRange);
		SpawnLocation.Y = FMath::RandRange(-SpawnRange, SpawnRange);
		GetWorld()->SpawnActor(SpawnClass, &SpawnLocation, &FRotator::ZeroRotator, FActorSpawnParameters() );
	}
	
}


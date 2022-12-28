// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PerfDemoSpawner.generated.h"

UCLASS(Blueprintable)
class UEPERFDEMOS_API APerfDemoSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APerfDemoSpawner();


UPROPERTY(EditDefaultsOnly, Category="Spawner")
	float SpawnRange {5000.f};
	
	UPROPERTY(EditDefaultsOnly, Category="Spawner")
	float SpawnCount {5000.f};

	UPROPERTY(EditDefaultsOnly, Category="Spawner")
	TSubclassOf<AActor> SpawnClass {nullptr};
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

};

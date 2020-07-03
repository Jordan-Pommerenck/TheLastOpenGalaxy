// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "master_laser.generated.h"

UCLASS()
class THELASTOPENGALAXY_API Amaster_laser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Amaster_laser();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// The base damage to be applied
	UPROPERTY(BlueprintReadWrite, Category = "Base Parameters")
		float base_damage{ 0 };

	// The base speed of the laser
	UPROPERTY(BlueprintReadWrite, Category = "Base Parameters")
		float base_speed{ 0 };

	// The base lifespan of the laser before destroyed
	UPROPERTY(BlueprintReadWrite, Category = "Base Parameters")
		float base_lifespan{ 0 };

	// The base scale of the laser
	UPROPERTY(BlueprintReadWrite, Category = "Base Parameters")
		float base_scale{ 0 };

	// The base scale of the laser
	UPROPERTY(BlueprintReadWrite, Category = "Base Parameters")
		float target_distance{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Targeting")
		AActor* hit_actor {
		NULL
	};

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

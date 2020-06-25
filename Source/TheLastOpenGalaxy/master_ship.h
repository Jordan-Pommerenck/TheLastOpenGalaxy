// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "master_ship.generated.h"

UCLASS()
class THELASTOPENGALAXY_API Amaster_ship : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Amaster_ship();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
		float min_speed = 0.001;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float base_speed;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float current_speed;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float base_acceleration;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float current_acceleration;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float base_pitch;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float base_yaw;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float base_roll;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float current_pitch;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float current_yaw;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float current_roll;

	UFUNCTION(BlueprintCallable, Category = "Transform")
		void update_pitch(float axis_value);

	UFUNCTION(BlueprintCallable, Category = "Transform")
		void update_yaw(float axis_value);

	UFUNCTION(BlueprintCallable, Category = "Transform")
		void update_roll(float axis_value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

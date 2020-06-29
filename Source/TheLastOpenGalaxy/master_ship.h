// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "master_ship.generated.h"

UENUM(BlueprintType)
enum class Allocation : uint8  {
	shields  UMETA(DisplayName = "shields"),
	weapons  UMETA(DisplayName = "weapons"),
	systems UMETA(DisplayName = "systems"),
	engines UMETA(DisplayName = "engines")
};

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

	// An Enumeration for the energy allocation
	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Allocation energy_allocation = Allocation::shields;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
		float min_speed = 0.001;

	// Maximum speed during hyperspeed
	UPROPERTY(BlueprintReadWrite, Category = "Hyperspeed")
		float hyper_speed;

	// The acceleration during hyperspeed
	UPROPERTY(BlueprintReadWrite, Category = "Hyperspeed")
		float hyper_accel;

	// The time elapsed before going to hyperspeed
	UPROPERTY(BlueprintReadWrite, Category = "Hyperspeed")
		float hyper_time;

	// The rotation scaling factor during hyperspeed
	UPROPERTY(BlueprintReadWrite, Category = "Hyperspeed")
		float hyper_rot_factor;

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

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int base_hull;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int current_hull;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int base_shields;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int current_shields;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int base_systems;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int current_systems;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int base_lasers;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int current_lasers;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int shd_rchrg;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int lsr_rchrg;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int sys_rchrg;

	UFUNCTION(BlueprintCallable, Category = "Transform")
		void update_pitch(float axis_value);

	UFUNCTION(BlueprintCallable, Category = "Transform")
		void update_yaw(float axis_value);

	UFUNCTION(BlueprintCallable, Category = "Transform")
		void update_roll(float axis_value);

	UFUNCTION(BlueprintCallable, Category = "Transform")
		void update_speed(float axis_value, float world_delta_seconds, bool rht_trggr);

	UFUNCTION(BlueprintCallable, Category = "Energy Allocation")
		void allocate_to_shields();

	UFUNCTION(BlueprintCallable, Category = "Energy Allocation")
		void allocate_to_weapons();

	UFUNCTION(BlueprintCallable, Category = "Energy Allocation")
		void allocate_to_systems();

	UFUNCTION(BlueprintCallable, Category = "Energy Allocation")
		void allocate_to_engines();

	UFUNCTION(BlueprintCallable, Category = "Hyperspeed")
		void init_hyper_params();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

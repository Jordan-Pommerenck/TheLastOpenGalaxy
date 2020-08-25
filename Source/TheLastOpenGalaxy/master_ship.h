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

UENUM(BlueprintType)
enum class Team : uint8 {
	red  UMETA(DisplayName = "red"),
	blue  UMETA(DisplayName = "blue")
};

UENUM(BlueprintType)
enum class Ship_Class : uint8 {
	fighter  UMETA(DisplayName = "fighter"),
	superiority  UMETA(DisplayName = "superiority"),
	bomber  UMETA(DisplayName = "bomber")
};

UENUM(BlueprintType)
enum class Laser_Type : uint8 {
	red  UMETA(DisplayName = "red"),
	blue  UMETA(DisplayName = "blue")
};

UENUM(BlueprintType)
enum class Warhead_Type : uint8 {
	missile  UMETA(DisplayName = "missile"),
	torpedo  UMETA(DisplayName = "torpedo")
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
		Allocation energy_allocation {
		Allocation::shields
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Team my_team {
		Team::red
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Ship_Class my_class {
		Ship_Class::fighter
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Laser_Type my_laser_type {
		Laser_Type::red
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Warhead_Type my_warhead_type {
		Warhead_Type::missile
	};

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
		float min_speed{ 0.001 };

	// Maximum speed during hyperspeed
	UPROPERTY(BlueprintReadWrite, Category = "Hyperspeed")
		float hyper_speed{ 0 };

	// The acceleration during hyperspeed
	UPROPERTY(BlueprintReadWrite, Category = "Hyperspeed")
		float hyper_accel{ 0 };

	// The time elapsed before going to hyperspeed
	UPROPERTY(BlueprintReadWrite, Category = "Hyperspeed")
		float hyper_time{ 0 };

	// The rotation scaling factor during hyperspeed
	UPROPERTY(BlueprintReadWrite, Category = "Hyperspeed")
		float hyper_rot_factor{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float base_speed{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float current_speed{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float base_acceleration{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float current_acceleration{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float base_pitch{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float base_yaw{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float base_roll{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float current_pitch{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float current_yaw{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		float current_roll{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int base_hull{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int current_hull{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int base_shields{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int current_shields{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int base_systems{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int current_systems{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int base_lasers{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int current_lasers{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int base_warheads{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int current_warheads{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int shd_rchrg{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int lsr_rchrg{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		int sys_rchrg{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float lsr_fire_rate{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float warhead_fire_rate{ 0 };

	// The scale of the ship in meters
	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float base_scale{ 0 };

	// The name of the ship
	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		FName my_name{""};

	UPROPERTY(BlueprintReadWrite, Category = "Targeting")
		AActor* my_target {
		NULL
	};

	UPROPERTY(BlueprintReadWrite, Category = "Sound")
		USoundBase* engine_hum {
		NULL
	};

	// The name of the primary weapon to fire
	//UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
	//	FName prm_weap_name;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		TArray<FVector> laser_locations;

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

	UFUNCTION(BlueprintCallable, Category = "Damage")
		void calculate_hull_damage(int hull_damage);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

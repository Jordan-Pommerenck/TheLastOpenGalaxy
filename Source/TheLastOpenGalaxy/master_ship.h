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
	blue  UMETA(DisplayName = "blue"),
	green  UMETA(DisplayName = "green"),
	yellow  UMETA(DisplayName = "yellow"),
	grey  UMETA(DisplayName = "grey")
};

UENUM(BlueprintType)
enum class Ship_Class : uint8 {
	fighter  UMETA(DisplayName = "Fighter"),
	superiority  UMETA(DisplayName = "Superiority"),
	bomber  UMETA(DisplayName = "Bomber"),
	anti_bomber  UMETA(DisplayName = "Anti-Bomber"),
	freighter  UMETA(DisplayName = "Freighter"),
	corvette  UMETA(DisplayName = "Corvette"),
	carrier  UMETA(DisplayName = "Carrier"),
	frigate  UMETA(DisplayName = "Frigate"),
	cruiser  UMETA(DisplayName = "Cruiser"),
	destroyer  UMETA(DisplayName = "Destroyer"),
	battlecruiser  UMETA(DisplayName = "Battlecruiser"),
	dreadnaught  UMETA(DisplayName = "Dreadnaught")
};

UENUM(BlueprintType)
enum class Laser_Type : uint8 {
	none  UMETA(DisplayName = "None"),
	lgtred  UMETA(DisplayName = "lgtred"),
	lgtgreen  UMETA(DisplayName = "lgtgreen"),
	lgtblue  UMETA(DisplayName = "lgtblue"),
	lgtviolet  UMETA(DisplayName = "lgtviolet"),
	medred  UMETA(DisplayName = "medred"),
	medgreen  UMETA(DisplayName = "medgreen"),
	medblue  UMETA(DisplayName = "medblue"),
	medviolet  UMETA(DisplayName = "medviolet"),
	hvyred  UMETA(DisplayName = "hvyred"),
	hvygreen  UMETA(DisplayName = "hvygreen"),
	hvyblue  UMETA(DisplayName = "hvyblue"),
	hvyviolet  UMETA(DisplayName = "hvyviolet"),
	megared  UMETA(DisplayName = "megared"),
	megagreen  UMETA(DisplayName = "megagreen"),
	megablue  UMETA(DisplayName = "megablue"),
	megaviolet  UMETA(DisplayName = "megaviolet"),
	missile  UMETA(DisplayName = "missile"),
	hvymissile  UMETA(DisplayName = "hvymissile"),
	torpedo  UMETA(DisplayName = "torpedo"),
	hvytorpedo  UMETA(DisplayName = "hvytorpedo"),
	warhead  UMETA(DisplayName = "warhead"),
	hvywarhead  UMETA(DisplayName = "hvywarhead"),
	bomb  UMETA(DisplayName = "bomb")
};

UENUM(BlueprintType)
enum class Weapon_Select : uint8 {
	primary  UMETA(DisplayName = "Primary"),
	secondary  UMETA(DisplayName = "Secondary"),
	tertiary UMETA(DisplayName = "Tertiary"),
	quaternary UMETA(DisplayName = "Quaternary"),
	quinary UMETA(DisplayName = "Quinary"),
	senary UMETA(DisplayName = "Senary"),
	septenary UMETA(DisplayName = "Septenary"),
	octonary UMETA(DisplayName = "Octonary"),
	nonary UMETA(DisplayName = "Nonary"),
	denary UMETA(DisplayName = "Denary")
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
		Laser_Type prmy_weap_type {
		Laser_Type::none
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Laser_Type scdy_weap_type {
		Laser_Type::none
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Laser_Type trty_weap_type {
		Laser_Type::none
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Laser_Type qtry_weap_type {
		Laser_Type::none
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Laser_Type qnry_weap_type {
		Laser_Type::none
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Laser_Type snry_weap_type {
		Laser_Type::none
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Laser_Type spty_weap_type {
		Laser_Type::none
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Laser_Type octy_weap_type {
		Laser_Type::none
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Laser_Type nnry_weap_type {
		Laser_Type::none
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Laser_Type dnry_weap_type {
		Laser_Type::none
	};

	UPROPERTY(BlueprintReadWrite, Category = "Enum")
		Weapon_Select which_weapon {
		Weapon_Select::primary
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
		float prmy_fire_rate{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float scdy_fire_rate{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float trty_fire_rate{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float qtry_fire_rate{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float qnry_fire_rate{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float snry_fire_rate{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float spty_fire_rate{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float octy_fire_rate{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float nnry_fire_rate{ 0 };

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float dnry_fire_rate{ 0 };

	// The scale of the ship in meters
	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float base_scale{ 0 };

	// Whether the ship is disabled or not
	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		bool i_am_disabled{ false };

	// Whether the ship is hypering or not
	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		bool i_am_hypering{ false };

	// Whether the ship needs to be escorted or not
	UPROPERTY(BlueprintReadWrite, Category = "Escorting")
		bool i_need_escorting{ false };

	// Whether the ship will find and escort nearest ship
	UPROPERTY(BlueprintReadWrite, Category = "Escorting")
		bool i_need_to_escort{ false };

	// Whether the ship needs to loop through waypoint array or hyper out
	UPROPERTY(BlueprintReadWrite, Category = "Escorting")
		bool waypoint_looping{ false };

	// What array point the ship is currently at
	UPROPERTY(BlueprintReadWrite, Category = "Escorting")
		int waypoint_index{ 0 };

	// Whether the ship needs to be disabled or not
	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		bool i_need_disabled{ false };

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

	UPROPERTY(BlueprintReadWrite, Category = "Targeting")
		TArray<AActor*> fighter_targets{
		NULL
	};

	// The rotator to update
	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		FRotator update_rotator {
		0, 0, 0
	};

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
		TArray<FVector> waypoints;

	// The array of vectors to store each primary weapon spawn point
	UPROPERTY(BlueprintReadWrite, Category = "Weapon Locations")
		TArray<FVector> prmy_locations;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon Locations")
		TArray<FVector> scdy_locations;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon Locations")
		TArray<FVector> trty_locations;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon Locations")
		TArray<FVector> qtry_locations;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon Locations")
		TArray<FVector> qnry_locations;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon Locations")
		TArray<FVector> snry_locations;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon Locations")
		TArray<FVector> spty_locations;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon Locations")
		TArray<FVector> octy_locations;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon Locations")
		TArray<FVector> nnry_locations;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon Locations")
		TArray<FVector> dnry_locations;

	UPROPERTY(BlueprintReadWrite, Category = "Base Parameter")
		float collision_diameter{ 0 };

	UFUNCTION(BlueprintCallable, Category = "Transform")
		void update_pitch(float axis_value, float world_delta_seconds);

	UFUNCTION(BlueprintCallable, Category = "Transform")
		void update_yaw(float axis_value, float world_delta_seconds);

	UFUNCTION(BlueprintCallable, Category = "Transform")
		void update_roll(float axis_value, float world_delta_seconds);

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

	UFUNCTION(BlueprintCallable, Category = "System")
		void check_if_disabled();

	UFUNCTION(BlueprintCallable, Category = "System")
		void calculate_systems_damage(int system_damage);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

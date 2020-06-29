// Fill out your copyright notice in the Description page of Project Settings.


#include "master_ship.h"

// Sets default values
Amaster_ship::Amaster_ship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Amaster_ship::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Amaster_ship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector new_location = FVector((current_speed * DeltaTime), 0, 0); //+ GetActorLocation();

	FRotator new_rotation = FRotator(current_pitch * DeltaTime, current_yaw * DeltaTime, current_roll * DeltaTime); // +(GetActorRotation());
	
	AddActorLocalOffset(new_location, false, 0, ETeleportType::None);
	AddActorLocalRotation(new_rotation, false, 0, ETeleportType::None);
	// SetActorLocationAndRotation(GetActorLocation(), GetActorRotation(), false, 0, ETeleportType::None);

}

// Called to bind functionality to input
void Amaster_ship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void Amaster_ship::update_pitch(float axis_value) {
	if (energy_allocation == Allocation::engines) {
		current_pitch = -base_pitch * hyper_rot_factor * axis_value;
	}
	else {
		current_pitch = -base_pitch * axis_value;
	}
}

void Amaster_ship::update_yaw(float axis_value) {
	if (energy_allocation == Allocation::engines) {
		current_yaw = base_yaw * hyper_rot_factor * axis_value;
	}
	else {
		current_yaw = base_yaw * axis_value;
	}
}

void Amaster_ship::update_roll(float axis_value) {
	if (energy_allocation == Allocation::engines) {
		current_roll = -base_roll * hyper_rot_factor * axis_value;
	}
	else {
		current_roll = base_roll * axis_value;
	}
}

void Amaster_ship::update_speed(float axis_value, float world_delta_seconds, bool rht_trggr) {
	if (energy_allocation == Allocation::engines &&  current_speed < hyper_speed) {
		current_speed += hyper_accel * world_delta_seconds;
		current_acceleration = 0;
	}
	else {
		int the_trggr = -1;
		if (axis_value > 0 && (current_speed <= base_speed)) {
			if (rht_trggr) {
				the_trggr = 1;
			}
			current_acceleration = axis_value * base_acceleration * the_trggr;
			float target_speed = current_speed + (current_acceleration * world_delta_seconds);

			current_speed = FMath::Clamp(FMath::FInterpTo(current_speed, target_speed, world_delta_seconds, 4.0f), min_speed, base_speed);
		}
		else if (current_speed > base_speed) {
			current_speed -= hyper_accel * world_delta_seconds;
			current_acceleration = 0;
		}
		else {
			current_acceleration = 0;
		}
	}
}

void Amaster_ship::allocate_to_shields() {
	if (current_shields != base_shields) {
		current_shields = FMath::Clamp(current_shields + shd_rchrg, 0, base_shields);
	}
}

void Amaster_ship::allocate_to_weapons() {
	if (current_lasers != base_lasers) {
		current_lasers = FMath::Clamp(current_lasers + lsr_rchrg, 0, base_lasers);
	}
}

void Amaster_ship::allocate_to_systems() {
	if (current_systems != base_systems) {
		current_systems = FMath::Clamp(current_systems + sys_rchrg, 0, base_systems);
	}
}

void Amaster_ship::allocate_to_engines() {
	if (current_shields != 0) {
		current_shields = FMath::Clamp(current_shields - shd_rchrg, 0, base_shields);
	}
	if (current_lasers != 0) {
		current_lasers = FMath::Clamp(current_lasers - lsr_rchrg, 0, base_lasers);
	}
}

void Amaster_ship::init_hyper_params() {
	hyper_speed = 10 * base_speed;
	hyper_accel = 0.1 * base_acceleration;
	hyper_rot_factor = 0;
	hyper_time = 3;
}
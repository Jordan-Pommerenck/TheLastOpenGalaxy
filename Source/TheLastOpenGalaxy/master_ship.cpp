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
	current_pitch = base_pitch * axis_value;
}

void Amaster_ship::update_yaw(float axis_value) {
	current_yaw = base_yaw * axis_value;
}

void Amaster_ship::update_roll(float axis_value) {
	current_roll = base_roll * axis_value;
}
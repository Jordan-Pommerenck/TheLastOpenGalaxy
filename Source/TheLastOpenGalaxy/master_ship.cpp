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

	FVector new_location = GetActorLocation() + (current_speed * DeltaTime) * GetActorForwardVector();

	FRotator new_rotation = FRotator(FQuat(FRotator(current_pitch * DeltaTime, current_yaw * DeltaTime, current_roll * DeltaTime)) * FQuat(GetActorRotation()));

	SetActorLocationAndRotation(new_location, new_rotation, false, 0, ETeleportType::None);

}

// Called to bind functionality to input
void Amaster_ship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
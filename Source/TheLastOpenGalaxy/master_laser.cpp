// Fill out your copyright notice in the Description page of Project Settings.


#include "master_laser.h"

// Sets default values
Amaster_laser::Amaster_laser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Amaster_laser::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Amaster_laser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.

/*
This code was originally written by ZkarmaKun and edited by HerrDrFink and can be
found at answers.unrealengine.com

https://answers.unrealengine.com/questions/188001/ifilemanager-and-ifilemanagergeneric-return-null-f.html
*/

#pragma once

#include "CoreMinimal.h"
#include "HAL/FileManagerGeneric.h"
#include "Misc/Paths.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "read_directory_files.generated.h"

/**
 * 
 */
UCLASS()
class THELASTOPENGALAXY_API Uread_directory_files : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = FileManager)
        static TArray<FString> get_directory_files(FString Directory, FString Extension);
	
};

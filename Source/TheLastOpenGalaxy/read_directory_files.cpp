// Fill out your copyright notice in the Description page of Project Settings.


#include "read_directory_files.h"

TArray<FString> Uread_directory_files::get_directory_files(FString Directory, FString Extension)
{
    TArray<FString> output;
    output.Empty();
    if (FPaths::DirectoryExists(Directory))
    {
        FString path = Directory + Extension;
        FFileManagerGeneric::Get().FindFiles(output, *path, true, false);
    }
    return output;
}
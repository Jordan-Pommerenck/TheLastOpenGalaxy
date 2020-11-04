// Fill out your copyright notice in the Description page of Project Settings.


#include "read_directory_files.h"

void Uread_directory_files::get_directory_files(FString directory, FString extension, TArray<FString>& all_files, bool& return_value)
{
    all_files.Empty();

    if (FPaths::DirectoryExists(directory)) {
        FString path = directory + extension;
        FFileManagerGeneric::Get().FindFiles(all_files, *path, true, false);
        all_files.Sort();
    }
    return_value = bool(all_files.Num() > 0);
}
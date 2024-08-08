// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/Manager.h"

UManager::~UManager()
{
}

void UManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Data = NewObject<UDataManager>(this);
}

void UManager::Deinitialize()
{
	Super::Deinitialize();
	
}

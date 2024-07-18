// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/Manager.h"

void UManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Game = new GameManager;
	Data = NewObject<UDataManager>();
}

void UManager::Deinitialize()
{
	Super::Deinitialize();
	delete Game;

}

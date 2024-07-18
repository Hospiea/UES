// Fill out your copyright notice in the Description page of Project Settings.


#include "System/GMB.h"
#include "Spawner.h"
#include "Manager/Manager.h"

AGMB* AGMB::Instance = nullptr;

AGMB::AGMB()
{
	Instance = this;
}

void AGMB::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	Manager = GEngine->GetEngineSubsystem<UManager>();
}

void AGMB::BeginPlay()
{
	Super::BeginPlay();
	Spawner = GetWorld()->SpawnActor<ASpawner>();
}

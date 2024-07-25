// Fill out your copyright notice in the Description page of Project Settings.


#include "System/GMB.h"
#include "Spawner.h"
#include "Manager/Manager.h"
#include "Attacks/Basic/Basic.h"
#include "Components/AttackComponent.h"
#include "Blueprint/UserWidget.h"

AGMB* AGMB::Instance = nullptr;

AGMB::AGMB()
{
	Instance = this;
}

void AGMB::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	Manager = GEngine->GetEngineSubsystem<UManager>();
	Managers->SetWorld(GetWorld());
}

void AGMB::BeginPlay()
{
	Super::BeginPlay();
	Spawner = GetWorld()->SpawnActor<ASpawner>();
	Managers->Widget = GetWorld()->SpawnActor<AWidgetManager>();
	Managers->Game->KillCounts = 0;
	
	
}

void AGMB::EndPlay(const EEndPlayReason::Type reason)
{
	Super::EndPlay(reason);
	Managers->PoolClear();
	
	

	for (auto& temp : Managers->Game->Player->GetAttackComponent()->GetAttackTypes())
	{
		temp->GetLevel() = 0;
	}
}

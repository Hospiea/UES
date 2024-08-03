// Fill out your copyright notice in the Description page of Project Settings.


#include "System/GMB.h"
#include "Spawner.h"
#include "Manager/Manager.h"
#include "Attacks/Basic/Basic.h"
#include "Components/AttackComponent.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

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
	Managers->Widget = GetWorld()->SpawnActor<AWidgetManager>();
	Managers->Sound = GetWorld()->SpawnActor<ASoundManager>();
}

void AGMB::BeginPlay()
{
	Super::BeginPlay();
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

	Managers->Widget->GetWeaponImages().Empty();
	Managers->Widget->GetPassiveImages().Empty();

}

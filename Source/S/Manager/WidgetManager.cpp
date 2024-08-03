// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/WidgetManager.h"
#include "Data/WidgetAsset.h"
#include "Widgets/Battle.h"
#include "System/GMB.h"
#include "System/PC.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Widgets/LevelUpSkillSlot.h"
#include "Kismet/GameplayStatics.h"
#include "System/Spawner.h"

AWidgetManager::AWidgetManager()
{
	PrimaryActorTick.bCanEverTick = false;
	static ConstructorHelpers::FObjectFinder<UWidgetAsset> widgets(TEXT("/Script/S.WidgetAsset'/Game/Assets/Data/Widgets.Widgets'"));

	Widgets = widgets.Object;
}

void AWidgetManager::LevelUp()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	PopupWidget = CreateWidget(GetWorld(), Widgets->Widgets["LevelUp"]);
	PopupWidget->AddToViewport();
}

void AWidgetManager::Pause()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	PopupWidget = CreateWidget(GetWorld(), Widgets->Widgets["Pause"]);
	PopupWidget->AddToViewport();
	

}

void AWidgetManager::RemovePopupWidget()
{
	PopupWidget->RemoveFromParent();
	Managers->Controller->Resume();
}

void AWidgetManager::EndOpening()
{
	CurrentWidget->RemoveFromParent();
	CurrentWidget = CreateWidget(GetWorld(), Widgets->Widgets["Intro"]);
	CurrentWidget->AddToViewport();
}

void AWidgetManager::ClickToStart()
{
	CurrentWidget->RemoveFromParent();
	CurrentWidget = CreateWidget(GetWorld(), Widgets->Widgets["Battle"]);
	CurrentWidget->AddToViewport();
	GetWorld()->SpawnActor<ASpawner>();

	Managers->Sound->PlayBgm("Stage1");
}

void AWidgetManager::ClickToLobby()
{
	CurrentWidget->RemoveFromParent();
	CurrentWidget = CreateWidget(GetWorld(), Widgets->Widgets["Lobby"]);
	CurrentWidget->AddToViewport();
}

void AWidgetManager::BeginPlay()
{
	Super::BeginPlay();
	CurrentWidget = CreateWidget(GetWorld(), Widgets->Widgets["Opening"]);
	CurrentWidget->AddToViewport();

	
}

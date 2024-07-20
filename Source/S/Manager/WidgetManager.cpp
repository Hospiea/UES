// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/WidgetManager.h"
#include "Data/WidgetAsset.h"
#include "Widgets/Battle.h"
#include "Kismet/GameplayStatics.h"

AWidgetManager::AWidgetManager()
{
	PrimaryActorTick.bCanEverTick = false;
	static ConstructorHelpers::FObjectFinder<UWidgetAsset> widgets(TEXT("/Script/S.WidgetAsset'/Game/Assets/Data/Widgets.Widgets'"));
	Widgets = widgets.Object;
}

void AWidgetManager::LevelUp()
{
	PopupWidget = CreateWidget(GetWorld(), Widgets->Widgets["LevelUp"]);
	PopupWidget->AddToViewport();
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.0f);
}

void AWidgetManager::RemovePopupWidget()
{
	PopupWidget->RemoveFromParent();
}

void AWidgetManager::BeginPlay()
{
	Super::BeginPlay();
	CurrentWidget = CreateWidget(GetWorld(), Widgets->Widgets["Battle"]);
	CurrentWidget->AddToViewport();
	

}


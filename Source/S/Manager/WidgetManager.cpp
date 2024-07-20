// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/WidgetManager.h"
#include "Data/WidgetAsset.h"

AWidgetManager::AWidgetManager()
{
	PrimaryActorTick.bCanEverTick = false;
	static ConstructorHelpers::FObjectFinder<UWidgetAsset> widgets(TEXT("/Script/S.WidgetAsset'/Game/Assets/Data/Widgets.Widgets'"));
	Widgets = widgets.Object;
}

void AWidgetManager::BeginPlay()
{
	Super::BeginPlay();
	CurrentWidget = CreateWidget(GetWorld(), Widgets->Widgets["HUD"]);
	CurrentWidget->AddToViewport();
}


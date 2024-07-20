// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Battle.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UBattle::NativeConstruct()
{
	Super::NativeConstruct();
	Timer->SetText(FText::FromString(FString::Printf(TEXT("00:00"))));
	EXP_Gauge->SetPercent(0.0f);
}

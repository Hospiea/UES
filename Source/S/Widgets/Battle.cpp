// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Battle.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "GameObject/Player/User.h"
#include "System/GMB.h"

void UBattle::NativeConstruct()
{
	Super::NativeConstruct();
	Timer->SetText(FText::FromString(FString::Printf(TEXT("00:00"))));
	EXP_Gauge->SetPercent(0.0f);
}

void UBattle::NativeTick(const FGeometry& geo, float dt)
{
	Super::Tick(geo, dt);
	if (!User)
		User = Managers->Game->Player;


	EXP_Gauge->SetPercent(User->GetExpPercent());
	Money_Text->SetText(FText::FromString(FString::Printf(TEXT("Lv.%d"), User->GetLevel())));
	KillCount_Text->SetText(FText::FromString(FString::Printf(TEXT("Kills : %d"), Managers->Game->KillCounts)));
}

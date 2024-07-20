// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WidgetHUD.h"
#include "EXP.h"
#include "Components/ProgressBar.h"

void UWidgetHUD::SetPercent(const float& value)
{
	Exp->GetExp()->SetPercent(value);
}

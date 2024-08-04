// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HPBar.h"
#include "Components/ProgressBar.h"

void UHPBar::SetValue(const float& value)
{
	HP_Bar->SetPercent(value);
}

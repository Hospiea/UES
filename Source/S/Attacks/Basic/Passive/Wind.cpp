// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Passive/Wind.h"
#include "System/GMB.h"

void UWind::Init()
{
	Managers->Game->Player->GetStats().Speed *= (1.0f + 0.2f * GetLevel());
}

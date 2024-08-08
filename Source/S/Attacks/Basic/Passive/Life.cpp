// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Passive/Life.h"
#include "System/GMB.h"
#include "GameObject/Player/User.h"


void ULife::Init()
{
	Super::Init();
	Managers->Game->Player->GetStats().MaxHp *= (1 + 0.35f * (1 + GetLevel() + 1));
}

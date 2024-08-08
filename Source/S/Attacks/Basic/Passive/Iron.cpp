// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Passive/Iron.h"
#include "System/GMB.h"
#include "GameObject/Player/User.h"

void UIron::Init()
{
	Super::Init();
	Managers->Game->Player->GetStats().Defense *= (1 - 0.1f * (GetLevel() + 1));
}

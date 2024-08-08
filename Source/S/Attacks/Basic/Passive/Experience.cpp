// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Passive/Experience.h"
#include "System/GMB.h"
#include "GameObject/Player/User.h"

void UExperience::Init()
{
	Super::Init();
	Managers->Game->Player->GetStats().ExpValue *= (1 + (0.5 * GetLevel() + 1));
}

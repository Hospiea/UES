// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Passive/Circular.h"
#include "System//GMB.h"
#include "GameObject/Player/User.h"

void UCircular::Init()
{
	Super::Init();
	Managers->Game->Player->GetStats().HPRegen *= (1 + (0.05 * GetLevel()+1));
}

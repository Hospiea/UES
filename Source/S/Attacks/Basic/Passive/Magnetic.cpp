// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Passive/Magnetic.h"
#include "System/GMB.h"
#include "GameObject/Player/User.h"

void UMagnetic::Init()
{
	Super::Init();
	Managers->Game->Player->SetObtainRange(GetLevel()+1);
}

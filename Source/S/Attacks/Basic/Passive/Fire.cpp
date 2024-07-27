// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Passive/Fire.h"
#include "System/GMB.h"
#include "Components/AttackComponent.h"


void UFire::Init()
{
	for (auto& temp : Managers->Game->Player->GetAttackComponent()->GetAttackTypes())
	{
		temp->GetData().Damage *= (1.0f + 0.2f * (static_cast<float>(GetLevel())+1));
	}

}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Passive/Fire.h"

void UFire::Init()
{
	Data->Damage *= (1.0f + 0.2f * GetLevel());
}

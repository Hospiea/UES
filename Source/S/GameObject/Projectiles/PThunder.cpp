// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PThunder.h"
#include "System/GMB.h"

WeaponData APThunder::Data;

APThunder::APThunder()
{
	str = TEXT("Thunder");
}

void APThunder::BeginPlay()
{
	Super::BeginPlay();
	if (Data.Damage == 0.0f)
	{
		Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
		Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
		Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
		Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
		Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
	}
}

void APThunder::Tick(float dt)
{
	Super::Tick(dt);

}

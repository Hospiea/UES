// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PSpear.h"
#include "System/GMB.h"

FProjectileData APSpear::Data;

APSpear::APSpear()
{
	str = TEXT("Spear");
}

void APSpear::BeginPlay()
{
	Super::BeginPlay();
	if (Data.Damage == 0.0f)
	{
		Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage[Level];
		Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate[Level];
		Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range[Level];
		Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration[Level];
		Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed[Level];
	}
}

void APSpear::Tick(float dt)
{
	Super::Tick(dt);

}

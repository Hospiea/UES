// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PAxe.h"
#include "System/GMB.h"

FProjectileData APAxe::Data;

APAxe::APAxe()
{
	str = TEXT("Axe");

}

void APAxe::BeginPlay()
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

void APAxe::Tick(float dt)
{
	Super::Tick(dt);
	AddActorLocalRotation(FRotator(dt*1000, 0.0f, 0.0f));
}

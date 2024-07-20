// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PAxe.h"
#include "System/GMB.h"

WeaponData APAxe::Data;

APAxe::APAxe()
{
	str = TEXT("Axe");

}

void APAxe::BeginPlay()
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

void APAxe::Tick(float dt)
{
	Super::Tick(dt);
	AddActorLocalRotation(FRotator(dt*1000, 0.0f, 0.0f));
}

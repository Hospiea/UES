// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Hammer.h"
#include "System/GMB.h"
#include "Data/WeaponAsset.h"


void UHammer::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Hammer"];
	SetWeaponData();
}

void UHammer::BasicAttack(const FVector2D& Dir)
{

}

void UHammer::SetWeaponData()
{
	Super::SetWeaponData();
	FName str = TEXT("Hammer");


	Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
	Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
	Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
	Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
	Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
}

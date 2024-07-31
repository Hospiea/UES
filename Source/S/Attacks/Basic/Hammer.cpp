// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Hammer.h"
#include "GameObject/Projectiles/PHammer.h"
#include "System/GMB.h"
#include "Components/Center.h"
#include "Data/WeaponAsset.h"


UHammer::UHammer(const FObjectInitializer& Init)
	:Super(Init)
{
	APHammer::Basic = this;
}

void UHammer::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Hammer"];
	SetWeaponData();
}

void UHammer::BasicAttack(const FVector2D& Dir)
{
	APHammer* Hammer = GetWorld()->SpawnActor<APHammer>(WeaponClass, FVector::ZeroVector, FRotator::ZeroRotator);
	Hammer->AttachToComponent(User->GetCenter(), FAttachmentTransformRules::KeepRelativeTransform);
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

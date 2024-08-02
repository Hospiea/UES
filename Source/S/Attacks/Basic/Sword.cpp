// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Sword.h"
#include "GameObject/Projectiles/PSword.h"
#include "GameObject/Player/User.h"
#include "Components/Center.h"
#include "Data/WeaponAsset.h"
#include "System/GMB.h"

USword::USword(const FObjectInitializer& Init)
	:Super(Init)
{
	APSword::Basic = this;
}

void USword::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Sword"];
	SetWeaponData();

}

void USword::BasicAttack(const FVector2D& Dir)
{
	Super::BasicAttack(Dir);
	APSword* temp = Managers->GetPoolManager<APSword>()->Get(WeaponClass, SpawnLocation, FRotator(Angle, 0.0f, 0.0f));
	temp->AttachToComponent(User->GetCenter(), FAttachmentTransformRules::KeepWorldTransform);
	temp->Span(Data.Duration * User->GetStats().ProjectileDuration);
}

void USword::SetWeaponData()
{
	FName str = TEXT("Sword");


	Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
	Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
	Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
	Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
	Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Negative.h"
#include "Data/WeaponAsset.h"
#include "GameObject/Player/User.h"
#include "System/GMB.h"
#include "GameObject/Projectiles/PNegative.h"
#include "GameFramework/CharacterMovementComponent.h"

UNegative::UNegative(const FObjectInitializer& Init)
	:Super(Init)
{
	APNegative::Basic = this;
}

void UNegative::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Negative"];
	SetWeaponData();
}

void UNegative::BasicAttack(const FVector2D& Dir)
{
	SpawnLocation = FVector(Dir.X, 10.0f, Dir.Y);
	APNegative* temp = Managers->GetPoolManager<APNegative>()->Get(WeaponClass, SpawnLocation, FRotator(0.0f, 0.0f, 0.0f));

}

void UNegative::SetWeaponData()
{
	Super::SetWeaponData();
	FName str = TEXT("Negative");

	Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
	Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
	Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
	Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
	Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
}

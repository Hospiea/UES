// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Staff.h"
#include "Data/WeaponAsset.h"
#include "GameObject/Projectiles/PThunder.h"
#include "GameObject/Player/User.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "System/GMB.h"


UStaff::UStaff(const FObjectInitializer& Init)
	:Super(Init)
{
	APThunder::Basic = this;
}

void UStaff::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Staff"];
	SetWeaponData();
}


void UStaff::BasicAttack(const FVector2D& Dir)
{
	SpawnLocation = FVector(Dir.X, 10.0f, Dir.Y);
	APThunder* temp = World->SpawnActor<APThunder>(WeaponClass, SpawnLocation, FRotator(0.0f, 0.0f, 0.0f));
}

void UStaff::SetWeaponData()
{
	FName str = TEXT("Thunder");

	Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
	Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
	Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
	Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
	Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;

}

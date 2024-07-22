// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Staff.h"
#include "Data/WeaponAsset.h"
#include "GameObject/Projectiles/PThunder.h"
#include "GameObject/Player/User.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "System/GMB.h"

void UStaff::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Staff"];

}


void UStaff::BasicAttack(const FVector2D& Dir)
{
	if (Data->Damage == 0.0f)
		SetWeaponData();
	SpawnLocation = FVector(Dir.X, 10.0f, Dir.Y);
	APThunder* temp = World->SpawnActor<APThunder>(WeaponClass, SpawnLocation, FRotator(0.0f, 0.0f, 0.0f));

}

void UStaff::SetWeaponData()
{
	//Data = APThunder::Data;
	FName str = TEXT("Thunder");

	Data->Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage[APThunder::Level];
	Data->Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate[APThunder::Level];
	Data->Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range[APThunder::Level];
	Data->Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration[APThunder::Level];
	Data->Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed[APThunder::Level];

}

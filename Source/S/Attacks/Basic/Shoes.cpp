// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Shoes.h"
#include "Data/WeaponAsset.h"
#include "GameObject/Player/User.h"
#include "GameObject/Projectiles/PShoes.h"
#include "System/GMB.h"

void UShoes::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Shoes"];
}

void UShoes::BasicAttack(const FVector2D& Dir)
{
	if (Data == nullptr)
		Init();

	SpawnLocation = User->GetActorLocation() - FVector(0.0f, 1.0f, 0.0f);

	APShoes* temp = World->SpawnActor<APShoes>(WeaponClass, SpawnLocation, FRotator(0.0f, 0.0f, 0.0f));
}

void UShoes::SetWeaponData()
{
	Super::SetWeaponData();

	FName str = TEXT("Shoes");

	Data->Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage[APShoes::Level];
	Data->Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate[APShoes::Level];
	Data->Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range[APShoes::Level];
	Data->Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration[APShoes::Level];
	Data->Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed[APShoes::Level];
}
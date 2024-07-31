// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Shoes.h"
#include "Data/WeaponAsset.h"
#include "GameObject/Player/User.h"
#include "GameObject/Projectiles/PShoes.h"
#include "System/GMB.h"


UShoes::UShoes(const FObjectInitializer& Init)
	:Super(Init)
{
	APShoes::Basic = this;
}

void UShoes::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Shoes"];
	SetWeaponData();
}

void UShoes::BasicAttack(const FVector2D& Dir)
{
	SpawnLocation = User->GetActorLocation() - FVector(0.0f, 1.0f, 0.0f);
	//APShoes* temp = World->SpawnActor<APShoes>(WeaponClass, SpawnLocation, FRotator(0.0f, 0.0f, 0.0f));
	APShoes* temp = Managers->GetPoolManager<APShoes>()->Get(WeaponClass, SpawnLocation, FRotator(0.0f, 0.0f, 0.0f));
}

void UShoes::SetWeaponData()
{
	Super::SetWeaponData();

	FName str = TEXT("Shoes");

	Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
	Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
	Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
	Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
	Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
}
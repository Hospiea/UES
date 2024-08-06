// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Positive.h"
#include "GameObject/Projectiles/PPositive.h"
#include "Data/WeaponAsset.h"
#include "System/GMB.h"
#include "Components/DetectComponent.h"

UPositive::UPositive(const FObjectInitializer& Init)
	:Super(Init)
{
	APPositive::Basic = this;

}

void UPositive::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Positive"];
	SetWeaponData();
}

void UPositive::BasicAttack(const FVector2D& Dir)
{
	//SpawnLocation = FVector(Dir.X, 10.0f, Dir.Y);
	FVector Loc = User->GetDetectComponent()->GetFarEnemy()->GetActorLocation();
	SpawnLocation = FVector(Loc.X, 10.0f, Loc.Z);
	APPositive* temp = Managers->GetPoolManager<APPositive>()->Get(WeaponClass, SpawnLocation, FRotator(0.0f, 0.0f, 0.0f));
}

void UPositive::SetWeaponData()
{
	Super::SetWeaponData();
	str = TEXT("Positive");

	Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
	Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
	Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
	Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
	Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
}

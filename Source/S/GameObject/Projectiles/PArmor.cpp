// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PArmor.h"
#include "System/GMB.h"
#include "GameObject/Enemy.h"

FProjectileData APArmor::Data;

APArmor::APArmor()
{
	PrimaryActorTick.bCanEverTick = false;
	str = TEXT("Armor");
}

void APArmor::BeginPlay()
{
	Super::BeginPlay();
	if (Data.Damage == 0.0f)
	{
		Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
		Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
		Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
		Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
		Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
	}
}

void APArmor::Tick(float dt)
{
	Super::Tick(dt);

}

void APArmor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->SetArmorDamaged();
	}
}

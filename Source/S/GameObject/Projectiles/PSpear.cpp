// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PSpear.h"
#include "System/GMB.h"

FProjectileData APSpear::Data;

APSpear::APSpear()
{
	str = TEXT("Spear");
}

void APSpear::BeginPlay()
{
	Super::BeginPlay();
	if (Data.Damage == 0.0f)
	{
		Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
		Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
		Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
		Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
		Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
	}
}

void APSpear::Tick(float dt)
{
	Super::Tick(dt);

}

void APSpear::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->GetDamage(Data.Damage);
	}
}

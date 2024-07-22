// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PShoes.h"
#include "System/GMB.h"
#include "GameObject/Enemy.h"

FProjectileData APShoes::Data;

APShoes::APShoes()
{
	PrimaryActorTick.bCanEverTick = true;
	str = TEXT("Shoes");
}

void APShoes::BeginPlay()
{
	Super::BeginPlay();
	if (Data.Damage == 0.0f)
	{
		Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage[Level];
		Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate[Level];
		Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range[Level];
		Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration[Level];
		Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed[Level];
	}

	Timer = 0.0f;
}

void APShoes::Tick(float dt)
{
	Super::Tick(dt);
	Timer += dt;
	if (Timer >= Data.Duration)
	{
		GetWorld()->DestroyActor(this);
	}
}

void APShoes::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->SetArmorDamaged();
	}
}

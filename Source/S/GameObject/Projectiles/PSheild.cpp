// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PSheild.h"
#include "System/GMB.h"
#include "GameObject/Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"

FProjectileData APSheild::Data;

APSheild::APSheild()
{
	PrimaryActorTick.bCanEverTick = false;
	str = TEXT("Sheild");
	Deletable = true;
}

void APSheild::BeginPlay()
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
}

void APSheild::Tick(float dt)
{
	Super::Tick(dt);

}

void APSheild::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->SetEnemyState(AEnemy::EnemyState::KnockBacked);
		FVector dir = enemy->GetActorLocation() - Managers->Game->Player->GetActorLocation();
		enemy->GetDamage(Data.Damage);
		dir.Y = 0.0f;
		dir.Normalize();
		dir *= 200.0f;
		enemy->GetCharacterMovement()->Velocity = dir;
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PSword.h"
#include "PaperSpriteComponent.h"
#include "GameObject/Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "System/GMB.h"

uint8 APSword::Level = 0;


APSword::APSword()
{
	PrimaryActorTick.bCanEverTick = true;
	str = TEXT("Sword");
}

void APSword::BeginPlay()
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

void APSword::Tick(float dt)
{
	Super::Tick(dt);
	
}

void APSword::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->SetEnemyState(AEnemy::EnemyState::KnockBacked);
		enemy->GetDamage(Data.Damage);
		FVector dir = GetActorLocation() - Managers->Game->Player->GetActorLocation();
		dir.Y = 0.0f;
		dir.Normalize();
		dir *= 200.0f;
		enemy->GetCharacterMovement()->Velocity = dir;
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PSword.h"
#include "PaperSpriteComponent.h"
#include "GameObject/Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "System/GMB.h"



APSword::APSword()
{
	str = TEXT("Sword");
}

void APSword::BeginPlay()
{
	Super::BeginPlay();
	if (Data.Damage == 0.0f)
	{
		Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(TEXT("Sword"), TEXT(""))->Damage;
		Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(TEXT("Sword"), TEXT(""))->Duration;
		Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(TEXT("Sword"), TEXT(""))->Range;
		Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(TEXT("Sword"), TEXT(""))->Rate;
		Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(TEXT("Sword"), TEXT(""))->Speed;
	}
	
}

void APSword::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
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

// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PSword.h"
#include "PaperSpriteComponent.h"
#include "GameObject/Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Attacks/Basic/Sword.h"
#include "System/GMB.h"

USword* APSword::Basic;

APSword::APSword()
{
	PrimaryActorTick.bCanEverTick = true;
	str = TEXT("Sword");
}

void APSword::SetBasic(UBasic* basic)
{
	Basic = Cast<USword>(basic);
}

void APSword::BeginPlay()
{
	Super::BeginPlay();
	
	
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
		if (enemy->GetEnemyState() == AEnemy::EnemyState::Dead)
			return;
		enemy->SetEnemyState(AEnemy::EnemyState::KnockBacked);
		enemy->GetDamage(Basic->GetData().Damage);
		
	}
}

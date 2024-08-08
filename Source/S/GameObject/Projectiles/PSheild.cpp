// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PSheild.h"
#include "System/GMB.h"
#include "GameObject/Enemy.h"
#include "Attacks/Basic/Sheild.h"
#include "GameFramework/CharacterMovementComponent.h"

USheild* APSheild::Basic;

APSheild::APSheild()
{
	PrimaryActorTick.bCanEverTick = false;
	str = TEXT("Sheild");
	Deletable = true;
}

void APSheild::SetBasic(UBasic* basic)
{
	Basic = Cast<USheild>(basic);
}

void APSheild::BeginPlay()
{
	Super::BeginPlay();

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
		if (enemy->GetEnemyState() == AEnemy::EnemyState::Dead)
			return;
		enemy->SetEnemyState(AEnemy::EnemyState::KnockBacked);
		enemy->GetDamage(Basic->GetData().Damage);
		GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Cyan, FString::Printf(TEXT("%f"), Basic->GetData().Damage));
		
	}
}

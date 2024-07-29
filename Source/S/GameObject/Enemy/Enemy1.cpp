// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Enemy/Enemy1.h"
#include "GameObject/Player/User.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "GameObject/Item/ExpOrb.h"
#include "System/GMB.h"

FEnemyStat AEnemy1::Stats;

AEnemy1::AEnemy1()
{
	PrimaryActorTick.bCanEverTick = true;
	ExpLv = 0;

	
}

void AEnemy1::BeginPlay()
{
	Super::BeginPlay();
	Stats.Speed = Managers->Data->EnemyStats->FindRow<FEnemyStats>(TEXT("1"), TEXT(""))->Speed;
	Stats.MaxHp = Managers->Data->EnemyStats->FindRow<FEnemyStats>(TEXT("1"), TEXT(""))->MaxHp;
	CurHp = Stats.MaxHp;
	bIsInitted = true;
}

void AEnemy1::Tick(float dt)
{
	Super::Tick(dt);
	

	switch (State)
	{
	case EnemyState::Normal:
	{
		FVector Location = Target->GetActorLocation() - GetActorLocation();
		Location.Normalize();

		FVector2D Dir = FVector2D(Location.X, Location.Z);
		Dir *= Managers->Data->EnemyStats->FindRow<FEnemyStats>(TEXT("1"), TEXT(""))->Speed;

		GetCharacterMovement()->Velocity = FVector(Dir.X, 0.0f, Dir.Y);
		break;
	}

	case EnemyState::KnockBacked:
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::RecoverFromKnockBack, 0.05f);
		SetEnemyState(EnemyState::Recovering);
		break;
	}
	}
}

void AEnemy1::GetDamage(const float& value)
{
	Super::GetDamage(value);

	if (CurHp <= 0.0f)
	{
		GetSprite()->SetFlipbook(Flipbooks->Flipbooks[TEXT("E1_Dead")]);
	}
}

void AEnemy1::OnEnable()
{
	Super::OnEnable();
	GetSprite()->SetFlipbook(Flipbooks->Flipbooks[TEXT("E1_Run")]);
}



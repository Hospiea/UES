// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Enemy/Enemy3.h"
#include "System/GMB.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"

FEnemyStat AEnemy3::Stats;

AEnemy3::AEnemy3()
{
	PrimaryActorTick.bCanEverTick = true;
	ExpLv = 0;
}

void AEnemy3::BeginPlay()
{
	Super::BeginPlay();
	Stats.Speed = Managers->Data->EnemyStats->FindRow<FEnemyStats>(TEXT("1"), TEXT(""))->Speed;
	Stats.MaxHp = Managers->Data->EnemyStats->FindRow<FEnemyStats>(TEXT("1"), TEXT(""))->MaxHp;
	CurHp = Stats.MaxHp;
	bIsInitted = true;
}

void AEnemy3::Tick(float dt)
{
	Super::Tick(dt);


	switch (State)
	{
	case EnemyState::Normal:
	{
		FVector Location = Target->GetActorLocation() - GetActorLocation();
		FVector2D Vel = FVector2D(Location.X, Location.Z);

		if (Vel.Size() < Distance)
		{
			SetEnemyState(EnemyState::Attacking);
			GetSprite()->SetFlipbook(Flipbooks->Flipbooks[TEXT("E3_Attack")]);
			GetCharacterMovement()->Velocity = FVector::ZeroVector;
			return;
		}


		Vel.Normalize();

		Vel *= Managers->Data->EnemyStats->FindRow<FEnemyStats>(TEXT("1"), TEXT(""))->Speed;

		GetCharacterMovement()->Velocity = FVector(Vel.X, 0.0f, Vel.Y);
		break;
	}

	case EnemyState::Attacking:
	{
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, [this]() {SetActive(false); }, 0.5f, FTimerManagerTimerParameters());
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

void AEnemy3::GetDamage(const float& value)
{
	Super::GetDamage(value);

	
}

void AEnemy3::OnEnable()
{
	Super::OnEnable();
	GetSprite()->SetFlipbook(Flipbooks->Flipbooks[TEXT("E3_Run")]);

}


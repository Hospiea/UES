// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Enemy/Enemy2.h"
#include "GameObject/Player/User.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "System/GMB.h"
#include "GameObject/EnemyProjectiles/ERange.h"

FEnemyStat AEnemy2::Stats;


AEnemy2::AEnemy2()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<AERange> rangeclass(TEXT("/Script/Engine.Blueprint'/Game/Assets/Blueprints/GameObjects/EnemyProjectile/BP_ERange.BP_ERange_C'"));

	

	RangeClass = rangeclass.Class;
	ExpLv = 1;

	Timer = 0.0f;
}

void AEnemy2::BeginPlay()
{
	Super::BeginPlay();
	Stats.Speed = Managers->Data->EnemyStats->FindRow<FEnemyStats>(TEXT("1"), TEXT(""))->Speed;
	Stats.MaxHp = Managers->Data->EnemyStats->FindRow<FEnemyStats>(TEXT("1"), TEXT(""))->MaxHp;
	CurHp = Stats.MaxHp;
	bIsInitted = true;
}

void AEnemy2::Tick(float dt)
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
			GetSprite()->SetFlipbook(Flipbooks->Flipbooks[TEXT("E2_Attack")]);
			GetCharacterMovement()->Velocity = FVector::ZeroVector;
			return;
		}
			

		Vel.Normalize();

		Vel *= Managers->Data->EnemyStats->FindRow<FEnemyStats>(TEXT("1"), TEXT(""))->Speed;

		GetCharacterMovement()->Velocity = FVector(Vel.X, 0.0f, Vel.Y);
		break;
	}

	case EnemyState::KnockBacked:
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::RecoverFromKnockBack, 0.05f);
		SetEnemyState(EnemyState::Recovering);
		break;
	}

	case EnemyState::Attacking:
	{
		FVector Location = Target->GetActorLocation() - GetActorLocation();
		FVector2D Vel = FVector2D(Location.X, Location.Z);
		Timer += dt;

		if (Vel.Size() > Distance)
		{
			SetEnemyState(EnemyState::Normal);
			GetSprite()->SetFlipbook(Flipbooks->Flipbooks[TEXT("E2_Idle")]);
			return;
		}

		if (Timer > 1.0f)
		{
			auto bullet = Managers->GetPoolManager<AERange>()->Get(RangeClass, GetActorLocation(), GetActorRotation());
			FVector Dir = Managers->Game->Player->GetActorLocation() - GetActorLocation();

			Dir.Normalize();
			Dir *= 200.0f;

			float angle = FMath::Atan2(Dir.Z, Dir.X);
			angle = FMath::RadiansToDegrees(angle);

			Timer = 0.0f;
			if (bullet)
			{
				bullet->GetCharacterMovement()->Velocity = Dir;
				bullet->SetActorRotation(FRotator(angle - 90.0f, 0.0f, 0.0f));
			}
		}

		break;
	}
	}
}

void AEnemy2::GetDamage(const float& value)
{
	Super::GetDamage(value);

	if (CurHp <= 0.0f)
	{
		GetSprite()->SetFlipbook(Flipbooks->Flipbooks[TEXT("E2_Dead")]);
	}
}

void AEnemy2::OnEnable()
{
	Super::OnEnable();
	GetSprite()->SetFlipbook(Flipbooks->Flipbooks[TEXT("E2_Idle")]);
}


void AEnemy2::RecoverFromKnockBack()
{
	State = EnemyState::Normal;
	GetSprite()->SetSpriteColor(FLinearColor::White);
}

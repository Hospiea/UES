// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Enemy/Enemy2.h"
#include "GameObject/Player/User.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "System/GMB.h"
#include "GameObject/EnemyProjectiles/ERange.h"

AEnemy2::AEnemy2()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<AERange> rangeclass(TEXT("/Script/Engine.Blueprint'/Game/Assets/Blueprints/GameObjects/EnemyProjectile/BP_ERange.BP_ERange_C'"));
	RangeClass = rangeclass.Class;


	Timer = 0.0f;
}

void AEnemy2::Tick(float dt)
{
	Super::Tick(dt);
	Timer += dt;

	if (Timer > 1.0f)
	{
		auto bullet = GetWorld()->SpawnActor<AERange>(RangeClass, GetActorLocation(), GetActorRotation());
		FVector Dir = Managers->Game->Player->GetActorLocation() - GetActorLocation();
		Dir.Normalize();
		Dir *= 200.0f;
		
		bullet->GetCharacterMovement()->Velocity = Dir;
		Timer = 0.0f;
	}

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

void AEnemy2::RecoverFromKnockBack()
{
	State = EnemyState::Normal;
	GetSprite()->SetSpriteColor(FLinearColor::White);
}

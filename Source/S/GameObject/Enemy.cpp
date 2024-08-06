// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Enemy.h"
#include "Components/CapsuleComponent.h"
#include "GameObject/Player/User.h"
#include "System/GMB.h"
#include "GameObject/Item/ExpOrb.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "System/AIC.h"
#include "GameObject/Item/ExpOrb.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/StaticMeshComponent.h"

bool AEnemy::bIsInitted = false;

AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Enemy"));
	static ConstructorHelpers::FClassFinder<AExpOrb> orbclass(TEXT("/Script/Engine.Blueprint'/Game/Assets/Blueprints/GameObjects/Item/BP_ExpOrb.BP_ExpOrb_C'"));
	OrbClass = orbclass.Class;
	CollisionProfileName = TEXT("Enemy");

	
}

void AEnemy::SetEnemyState(const EnemyState& state)
{
	if (state == EnemyState::KnockBacked)
	{
		if (State == state)
			return;
		FVector dir = GetActorLocation() - Managers->Game->Player->GetActorLocation();
		dir.Y = 0.0f;
		dir.Normalize();
		dir *= 200.0f;
		GetCharacterMovement()->Velocity = dir;
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &ThisClass::RecoverFromKnockBack, 0.05f);

	}
	
	else if (state == EnemyState::Dead)
	{
		GetCharacterMovement()->Velocity = FVector::ZeroVector;
		GetSprite()->SetSpriteColor(FLinearColor::White);
	}

	State = state;
}

void AEnemy::GetDamage(const float& value)
{
	Super::GetDamage(value);
	GetSprite()->SetSpriteColor(FLinearColor::Red);
	CurHp -= value;
	if (CurHp <= 0.0f && GetEnemyState() != EnemyState::Dead)
	{
		++Managers->Game->KillCounts;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEnemy::SetActiveHelper, 1.0f);
		GetCapsuleComponent()->SetCollisionProfileName(TEXT("Dead"));
		SetEnemyState(EnemyState::Dead);
		AExpOrb* orb = Managers->GetPoolManager<AExpOrb>()->Get(OrbClass, GetActorLocation());
		orb->SetExpLevel(ExpLv);
		orb->GetSprite()->SetRelativeLocation(FVector(0.0f, GetSprite()->GetRelativeLocation().Y - 1, 0.0f));
	}

	else if (GetEnemyState() == EnemyState::Dead)
	{

	}

	else
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::RecoverColor, 0.5f);

}

void AEnemy::SetArmorDamaged()
{
	IsArmored = true;
	FTimerHandle Handle;
	FTimerManagerTimerParameters Params;
	Params.bLoop = false;
	GetWorld()->GetTimerManager().SetTimer(Handle, [this]()->void {IsArmored = false; }, 0.5f, Params);
}

void AEnemy::Hold(const FVector& pos)
{
	if (GetEnemyState() == EnemyState::Dead)
		return;
	SetEnemyState(EnemyState::Hold);
	HoldPos = pos;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::RecoverFromKnockBack, 1.0f);
}

void AEnemy::Split(const FVector& pos)
{
	if (GetEnemyState() == EnemyState::Dead)
		return;
	SetEnemyState(EnemyState::Split);
	HoldPos = pos;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::RecoverFromKnockBack, 1.0f);
}

void AEnemy::PreInitializeComponents()
{
	Super::PreInitializeComponents();
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Enemy"));
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlap);
	AIController = NewObject<AAIC>(this);
	AIController->Possess(this);
	
	Target = Managers->Game->Player;
	if (bIsInitted) return;

}

void AEnemy::Tick(float dt)
{
	Super::Tick(dt);
	FVector Location = Target->GetActorLocation() - GetActorLocation();
	if (Location.X < 0.0f)
		GetSprite()->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));

	else
		GetSprite()->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));

	switch (GetEnemyState())
	{
	case EnemyState::Dead:
	{
		auto scale = GetSprite()->GetRelativeScale3D();
		GetSprite()->SetRelativeScale3D(scale - FVector(dt, dt, dt));
		break;
	}

	case EnemyState::Hold:
	{
		FVector Dir = HoldPos - GetActorLocation();
		GetCharacterMovement()->Velocity = Dir * 3;
		break;
	}

	case EnemyState::Split:
	{
		FVector Dir = GetActorLocation() - HoldPos;
		GetCharacterMovement()->Velocity = FVector(1000 / Dir.X, 0.0f, 1000 / Dir.Z);
		break;
	}
	}
}

void AEnemy::OnEnable()
{
	Super::OnEnable();
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Enemy"));
	GetSprite()->SetSpriteColor(FLinearColor::White);
	SetEnemyState(EnemyState::Normal);
	GetSprite()->SetRelativeScale3D(FVector(1, 1, 1));

}

void AEnemy::SetActiveHelper()
{
	SetActive(false);
}


void AEnemy::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AEnemy::RecoverColor()
{
	GetSprite()->SetSpriteColor(FLinearColor::White);
}

void AEnemy::RecoverFromKnockBack()
{
	State = EnemyState::Normal;
	GetSprite()->SetSpriteColor(FLinearColor::White);
}

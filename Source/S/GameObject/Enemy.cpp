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

bool AEnemy::bIsInitted = false;

AEnemy::AEnemy()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Enemy"));
	static ConstructorHelpers::FClassFinder<AExpOrb> orbclass(TEXT("/Script/Engine.Blueprint'/Game/Assets/Blueprints/GameObjects/Item/BP_ExpOrb.BP_ExpOrb_C'"));
	OrbClass = orbclass.Class;

}

void AEnemy::SetEnemyState(const EnemyState& state)
{
	State = state;

	if (state == EnemyState::KnockBacked)
	{
		FVector dir = GetActorLocation() - Managers->Game->Player->GetActorLocation();
		dir.Y = 0.0f;
		dir.Normalize();
		dir *= 200.0f;
		GetCharacterMovement()->Velocity = dir;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::RecoverColor, 0.05f);

	}
	
	else if (state == EnemyState::Dead)
	{
		GetCharacterMovement()->Velocity = FVector::ZeroVector;
		GetSprite()->SetSpriteColor(FLinearColor::White);
	}
}

void AEnemy::GetDamage(const float& value)
{
	Super::GetDamage(value);
	CurHp -= value;
	if (CurHp <= 0.0f)
	{
		++Managers->Game->KillCounts;
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		FTimerManagerTimerParameters Params;
		Params.bLoop = false;

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]() {SetActive(false); }, 1.0f, Params);
		GetCapsuleComponent()->SetCollisionProfileName(TEXT("Dead"));
		SetEnemyState(EnemyState::Dead);
		AExpOrb* orb = Managers->GetPoolManager<AExpOrb>()->Get(OrbClass, GetActorLocation());
		orb->SetExpLevel(ExpLv);
		orb->GetSprite()->SetRelativeLocation(FVector(0.0f, GetSprite()->GetRelativeLocation().Y - 1, 0.0f));
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

	if (GetEnemyState() == EnemyState::Dead)
	{
		auto color = GetSprite()->GetSpriteColor();
		GetSprite()->SetSpriteColor(color - FLinearColor(0, 0, 0, dt*3));
	}
}

void AEnemy::OnEnable()
{
	Super::OnEnable();
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Enemy"));
	GetSprite()->SetSpriteColor(FLinearColor::White);
	SetEnemyState(EnemyState::Normal);
}


void AEnemy::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AEnemy::RecoverColor()
{
	GetSprite()->SetSpriteColor(FLinearColor::White);
}

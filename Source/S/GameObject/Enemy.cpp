// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Enemy.h"
#include "Components/CapsuleComponent.h"
#include "GameObject/Player/User.h"
#include "System/GMB.h"
#include "GameObject/Item/ExpOrb.h"
#include "PaperFlipbookComponent.h"
#include "System/AIC.h"

AEnemy::AEnemy()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Enemy"));
	static ConstructorHelpers::FClassFinder<AExpOrb> orbclass(TEXT("/Script/Engine.Blueprint'/Game/Assets/Blueprints/GameObjects/Item/BP_ExpOrb.BP_ExpOrb_C'"));
	OrbClass = orbclass.Class;

}

void AEnemy::GetDamage(const float& value)
{
	CurHp -= value;
	if (CurHp <= 0.0f)
	{
		++Managers->Game->KillCounts;
		SetActive(false);

		AExpOrb* orb = Managers->GetPoolManager<AExpOrb>()->Get(OrbClass, GetActorLocation());
		orb->SetExpLevel(ExpLv);
	}
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
	Stats.Speed = Managers->Data->EnemyStats->FindRow<FEnemyStats>(TEXT("1"), TEXT(""))->Speed;
	Stats.MaxHp = Managers->Data->EnemyStats->FindRow<FEnemyStats>(TEXT("1"), TEXT(""))->MaxHp;
	CurHp = Stats.MaxHp;
}

void AEnemy::Tick(float dt)
{
	Super::Tick(dt);
	FVector Location = Target->GetActorLocation() - GetActorLocation();
	if (Location.X < 0.0f)
		GetSprite()->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));

	else
		GetSprite()->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
}

void AEnemy::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

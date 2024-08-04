// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Player/User.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/Center.h"
#include "Attacks/Basic/Sword.h"
#include "Attacks/Basic/Basic.h"
#include "Components/CapsuleComponent.h"
#include "System/GMB.h"
#include "Data/ObjectStatData.h"
#include "Components/SWidgetComponent.h"
#include "Attacks/Basic/Axe.h"
#include "Attacks/Basic/Spear.h"
#include "Attacks/Basic/Staff.h"
#include "Components/DetectComponent.h"
#include "System/PC.h"
#include "Components/AnimationComponent.h"
#include "Components/AttackComponent.h"
#include "GameObject/EnemyProjectiles.h"
#include "Obtainer.h"


AUser::AUser()
{
	Center = CreateDefaultSubobject<UCenter>(TEXT("CenterComponent"));
	Center->SetupAttachment(RootComponent);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Player"));

	HPBar = CreateDefaultSubobject<USWidgetComponent>(TEXT("HPBar"));
	HPBar->SetupAttachment(RootComponent);

	DetectComponent = CreateDefaultSubobject<UDetectComponent>(TEXT("DetectComponent"));
	DetectComponent->SetupAttachment(RootComponent);

	AttackComponent = CreateDefaultSubobject<UAttackComponent>(TEXT("AttackComponent"));

	AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));

	CollisionProfileName = TEXT("Player");

}



void AUser::GetExp(const float& value)
{
	CurExp += value;

	if (CurExp >= RequiredExp[Level]->RequiredExp)
	{
		CurExp -= RequiredExp[Level]->RequiredExp;
		LevelUp();
		++Level;
	}
}

void AUser::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	if(Managers)
		Managers->Game->Player = this;

	
	
	DetectComponent->SetPlayer(this);
}

void AUser::BeginPlay()
{
	Super::BeginPlay();
	GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Idle"]);
	GetSprite()->SetRelativeLocation(FVector(0.0f, 1000.0f, 0.0f));

#pragma region Setting
	Stats.Speed = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->Speed;
	Stats.MaxHp = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->MaxHp;
	Stats.HPRegen = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->HPRegen;
	Stats.Defense = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->Defense;
	Stats.ExpValue = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->ExpValue;
	Stats.SourceValue = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->SourceValue;
	Stats.UntouchableTime = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->UntouchableTime;
	Stats.ObtainRange = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->ObtainRange;
	Stats.AttackValue = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->AttackValue;
	Stats.Rate = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->Rate;
	Stats.ProjectileSpeed = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->ProjectileSpeed;
	Stats.ProjectileSize = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->ProjectileSize;
	Stats.ProjectileDuration = Managers->Data->PlayerStats->FindRow<FPlayerStats>(TEXT("1"), TEXT(""))->ProjectileDuration;
	
	AnimationComponent->SetOwningGameObject(this);
	AnimationComponent->SetSprite(GetSprite());
	AnimationComponent->SetMovementComponent(GetCharacterMovement());

	AttackComponent->Init(GetWorld());

	Obtainer = GetWorld()->SpawnActor<AObtainer>();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlap);
	
	CurHp = Stats.MaxHp;
	Level = 0;
	CurExp = 0.0f;

	ExpData->GetAllRows<FExpData>(TEXT(""), RequiredExp);
#pragma endregion

}

void AUser::Tick(float dt)
{
	Super::Tick(dt);
	if (GetCharacterMovement()->Velocity.Size() == 0.0f)
		GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Idle"]);

	else
		GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Run"]);

}

void AUser::LevelUp()
{
	Managers->Widget->LevelUp();
}

void AUser::GetDamaged(const float& value)
{
	CurHp -= value;
	if (CurHp <= 0.0f)
	{

	}

	else
	{
		GetCapsuleComponent()->SetCollisionProfileName(TEXT("Nothing"));
		GetSprite()->SetSpriteColor(FLinearColor(1, 1, 1, 0.3f));
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, [this]() {GetDamagedHelper(); }, 0.5f, FTimerManagerTimerParameters());
	}
}

void AUser::GetDamagedHelper()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Player"));
	GetSprite()->SetSpriteColor(FLinearColor::White);
}

void AUser::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		GetDamaged(enemy->GetStat().Damage);
	}

	else if (AEnemyProjectiles* penem = Cast<AEnemyProjectiles>(OtherActor))
	{
		GetDamaged(5.0f);
	}
}

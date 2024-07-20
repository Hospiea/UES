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

AUser::AUser()
{
	Center = CreateDefaultSubobject<UCenter>(TEXT("CenterComponent"));
	Center->SetupAttachment(RootComponent);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Player"));

	HPBar = CreateDefaultSubobject<USWidgetComponent>(TEXT("HPBar"));
	HPBar->SetupAttachment(RootComponent);
}

void AUser::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	if(Managers)
		Managers->Game->Player = this;

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

}

void AUser::BeginPlay()
{
	Super::BeginPlay();
	GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Idle"]);

	// Initialize Weapon Here
	/*Basic = NewObject<USword>(this);
	Basic->SetPlayer(this);
	Basic->SetWorld(GetWorld());*/
	Basic = NewObject<USword>(this);
	Basic->SetPlayer(this);
	Basic->SetWorld(GetWorld());
	Basic->Init();

	CurHp = Stats.MaxHp;

}

void AUser::Tick(float dt)
{
	Super::Tick(dt);
	if (GetCharacterMovement()->Velocity.Size() == 0.0f)
		GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Idle"]);

	else
		GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Run"]);

}

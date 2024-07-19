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
}

void AUser::BeginPlay()
{
	Super::BeginPlay();
	GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Idle"]);

	Basic = NewObject<USword>(this);
	Basic->SetPlayer(this);
	Basic->SetWorld(GetWorld());

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

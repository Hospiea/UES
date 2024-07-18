// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Player/User.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/Center.h"
#include "Attacks/Basic/Sword.h"
#include "Attacks/Basic/Basic.h"
#include "Components/CapsuleComponent.h"

AUser::AUser()
{
	Center = CreateDefaultSubobject<UCenter>(TEXT("CenterComponent"));
	Center->SetupAttachment(RootComponent);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Player"));
}

void AUser::BeginPlay()
{
	Super::BeginPlay();
	GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Idle"]);

	Basic = NewObject<USword>(this);
	Basic->SetPlayer(this);
	Basic->SetWorld(GetWorld());
}

void AUser::Tick(float dt)
{
	Super::Tick(dt);
	if (GetCharacterMovement()->Velocity.Size() == 0.0f)
		GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Idle"]);

	else
		GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Run"]);
}

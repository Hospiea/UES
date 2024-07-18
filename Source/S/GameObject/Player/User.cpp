// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Player/User.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void AUser::BeginPlay()
{
	Super::BeginPlay();
	GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Idle"]);

}

void AUser::Tick(float dt)
{
	Super::Tick(dt);
	if (GetCharacterMovement()->Velocity.Size() == 0.0f)
		GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Idle"]);

	else
		GetSprite()->SetFlipbook(Flipbooks->Flipbooks["C1_Run"]);
}

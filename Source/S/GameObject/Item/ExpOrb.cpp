// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Item/ExpOrb.h"
#include "Data/FlipbookAsset.h"
#include "Components/CapsuleComponent.h"
#include "PaperFlipbookComponent.h"

TObjectPtr<UFlipbookAsset> AExpOrb::ExpSprites;

AExpOrb::AExpOrb()
{
	static ConstructorHelpers::FObjectFinder<UFlipbookAsset> expsprites(TEXT("/Script/S.FlipbookAsset'/Game/Assets/Data/Exp.Exp'"));
	ExpSprites = expsprites.Object;

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Orb"));
	Lv = 50;
}

void AExpOrb::SetExpLevel(const uint8& lv)
{
	Lv = lv;

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Orb"));
	switch (Lv)
	{
	case 0:
	{
		GetSprite()->SetFlipbook(ExpSprites->Flipbooks[TEXT("Exp0")]);
		break;
	}
	}
}

void AExpOrb::BeginPlay()
{
	Super::BeginPlay();

}

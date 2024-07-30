// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Item/ExpOrb.h"
#include "Data/FlipbookAsset.h"
#include "Components/CapsuleComponent.h"
#include "GameObject/Player/User.h"
#include "PaperFlipbookComponent.h"
#include "System/GMB.h"

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
	case 1:
	{
		GetSprite()->SetFlipbook(ExpSprites->Flipbooks[TEXT("Exp1")]);
		break;
	}

	}
}

void AExpOrb::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlap);
}

void AExpOrb::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AUser* user = Cast<AUser>(OtherActor))
	{
		user->GetExp(Lv+5);
		SetActive(false);
		Managers->Sound->PlaySfx(TEXT("Exp"));
	}

	
	
}

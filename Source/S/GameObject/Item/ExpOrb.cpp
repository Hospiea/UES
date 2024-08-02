// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Item/ExpOrb.h"
#include "Data/FlipbookAsset.h"
#include "Components/CapsuleComponent.h"
#include "GameObject/Player/User.h"
#include "PaperFlipbookComponent.h"
#include "System/GMB.h"
#include "System/AIC.h"
#include "GameFramework/CharacterMovementComponent.h"

TObjectPtr<UFlipbookAsset> AExpOrb::ExpSprites;

AExpOrb::AExpOrb()
{
	static ConstructorHelpers::FObjectFinder<UFlipbookAsset> expsprites(TEXT("/Script/S.FlipbookAsset'/Game/Assets/Data/Exp.Exp'"));
	ExpSprites = expsprites.Object;

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Orb"));
	Lv = 50;

	CollisionProfileName = TEXT("Orb");

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

void AExpOrb::Grabbed()
{
	bIsGrabbed = true;
}

void AExpOrb::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlap);
	auto temp = NewObject<AAIC>(this);
	temp->Possess(this);
	bIsGrabbed = false;
}

void AExpOrb::Tick(float dt)
{
	Super::Tick(dt);
	if (!bIsGrabbed) return;
	FVector Dir = Managers->Game->Player->GetActorLocation() - GetActorLocation();
	Dir *= 10.0f;
	GetCharacterMovement()->Velocity = Dir;
}

void AExpOrb::OnEnable()
{
	Super::OnEnable();
	bIsGrabbed = false;
	GetCharacterMovement()->Velocity = FVector::ZeroVector;

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

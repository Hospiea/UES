// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/GameObjects.h"
#include "Components/CapsuleComponent.h"
#include "Components/AnimationComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"

void AGameObjects::SetActive(bool flag)
{
	IsActive = flag;
	SetActorHiddenInGame(!flag);
	SetActorEnableCollision(flag);
	SetActorTickEnabled(flag);
	
	

	if (flag)
		OnEnable();

	else if (!flag)
		OnDisable();
}

void AGameObjects::OnEnable()
{
	GetCapsuleComponent()->SetCollisionProfileName(CollisionProfileName);
	GetSprite()->SetSpriteColor(FLinearColor::White);
}

void AGameObjects::OnDisable()
{
	CollisionProfileName = GetCapsuleComponent()->GetCollisionProfileName();
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Dead"));
}

AGameObjects::AGameObjects()
{
	GetCapsuleComponent()->SetCapsuleRadius(10.0f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(10.0f);

	static ConstructorHelpers::FObjectFinder<UFlipbookAsset> flipbooks(TEXT("/Script/S.FlipbookAsset'/Game/Assets/Data/Flipbooks.Flipbooks'"));
	Flipbooks = flipbooks.Object;

	AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
	
	GetCharacterMovement()->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Y);
	GetCharacterMovement()->SetPlaneConstraintEnabled(true);
	GetCharacterMovement()->GravityScale = 0.0f;
	++Order;
}

void AGameObjects::BeginPlay()
{
	Super::BeginPlay();
	GetSprite()->SetRelativeLocation(FVector(0.0f, Order, 0.0f));

	AnimationComponent->SetOwningGameObject(this);
	AnimationComponent->SetSprite(GetSprite());
	AnimationComponent->SetMovementComponent(GetCharacterMovement());
}

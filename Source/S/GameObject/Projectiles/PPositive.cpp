// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PPositive.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameObject/Enemy.h"
#include "Attacks/Basic/Positive.h"
#include "GameFramework/CharacterMovementComponent.h"

UPositive* APPositive::Basic;

APPositive::APPositive()
{
	str = TEXT("Positive");
}

void APPositive::BeginPlay()
{
	Super::BeginPlay();
	GetSprite()->SetRelativeLocation(FVector(0.0f, 0, 0.0f));
	bIsFirst = true;
}

void APPositive::Tick(float dt)
{
	Super::Tick(dt);
}

void APPositive::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (bIsFirst)
	{
		GetCapsuleComponent()->SetCapsuleHalfHeight(100.0f);
		GetCapsuleComponent()->SetCapsuleRadius(100.0f);
		bIsFirst = false;
	}
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, [enemy, this]() {
			enemy->GetDamage(Basic->GetData().Damage);
			enemy->Split(GetActorLocation()); 
			}, 0.5f, FTimerManagerTimerParameters());
		
	}
	Span(0.9f);
}

void APPositive::OnEnable()
{
	Super::OnEnable();
	GetCapsuleComponent()->SetCapsuleRadius(10.0f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(10.0f);
	GetSprite()->PlayFromStart();
}

void APPositive::OnDisable()
{
	Super::OnDisable();
	GetCapsuleComponent()->SetCapsuleRadius(0.1f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(0.1f);
	GetCharacterMovement()->Velocity = FVector::ZeroVector;

	bIsFirst = true;
}

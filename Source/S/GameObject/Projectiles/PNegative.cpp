// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PNegative.h"
#include "GameObject/Enemy.h"
#include "Attacks/Basic/Negative.h"
#include "Components/CapsuleComponent.h"

UNegative* APNegative::Basic;

APNegative::APNegative()
{
	str = TEXT("Negative");

}

void APNegative::BeginPlay()
{
	Super::BeginPlay();
	bIsFirst = true;
}

void APNegative::Tick(float dt)
{
	Super::Tick(dt);

}

void APNegative::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
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
		enemy->GetDamage(Basic->GetData().Damage);
	}

	SetActive(false);
}

void APNegative::OnEnable()
{
	Super::OnEnable();
	GetCapsuleComponent()->SetCapsuleRadius(10.0f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(10.0f);

	bIsFirst = true;
}

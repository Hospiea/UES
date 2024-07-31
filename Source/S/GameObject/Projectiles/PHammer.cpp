// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PHammer.h"
#include "Attacks/Basic/Hammer.h"
#include "GameObject/Enemy.h"

UHammer* APHammer::Basic;

APHammer::APHammer()
{
	str = TEXT("Hammer");
}

void APHammer::SetBasic(UBasic* basic)
{
	Basic = Cast<UHammer>(basic);
}

void APHammer::BeginPlay()
{
	Super::BeginPlay();
}

void APHammer::Tick(float dt)
{
	Super::Tick(dt);
	SetActorLocation(GetActorLocation() + GetActorForwardVector());
}

void APHammer::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->GetDamage(Basic->GetData().Damage);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PAxe.h"
#include "System/GMB.h"
#include "Attacks/Basic/Axe.h"
#include "GameFramework/CharacterMovementComponent.h"

UAxe* APAxe::Basic;

APAxe::APAxe()
{
	str = TEXT("Axe");
}

void APAxe::SetBasic(UBasic* basic)
{
	Basic = Cast<UAxe>(basic);
}

void APAxe::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void APAxe::Tick(float dt)
{
	Super::Tick(dt);
	AddActorLocalRotation(FRotator(dt*1000, 0.0f, 0.0f));
	
	

}

void APAxe::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->GetDamage(Basic->Data.Damage);
	}
}

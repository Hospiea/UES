// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PSpear.h"
#include "Attacks/Basic/Spear.h"
#include "System/GMB.h"

USpear* APSpear::Basic;

APSpear::APSpear()
{
	str = TEXT("Spear");
}

void APSpear::SetBasic(UBasic* basic)
{
	Basic = Cast<USpear>(basic);
}

void APSpear::BeginPlay()
{
	Super::BeginPlay();

}

void APSpear::Tick(float dt)
{
	Super::Tick(dt);

}

void APSpear::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->GetDamage(Basic->GetData().Damage);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PArmor.h"
#include "System/GMB.h"
#include "GameObject/Enemy.h"
#include "Attacks/Basic/Armor.h"

UArmor* APArmor::Basic;

APArmor::APArmor()
{
	PrimaryActorTick.bCanEverTick = false;
	str = TEXT("Armor");
}

void APArmor::SetBasic(UBasic* basic)
{
	Basic = Cast<UArmor>(basic);
}

void APArmor::BeginPlay()
{
	Super::BeginPlay();

}

void APArmor::Tick(float dt)
{
	Super::Tick(dt);

}

void APArmor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->SetArmorDamaged();
	}
}

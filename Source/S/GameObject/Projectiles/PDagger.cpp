// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PDagger.h"
#include "Attacks/Basic/Dagger.h"
#include "GameObject/Enemy.h"

UDagger* APDagger::Basic;

APDagger::APDagger()
{
	str = TEXT("Dagger");
}




void APDagger::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->GetDamage(Basic->GetData().Damage);
		SetActive(false);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PThunder.h"
#include "System/GMB.h"
#include "Attacks/Basic/Staff.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"


UStaff* APThunder::Basic;

APThunder::APThunder()
{
	PrimaryActorTick.bCanEverTick = true;
	str = TEXT("Thunder");
}

void APThunder::SetBasic(UBasic* basic)
{
	Basic = Cast<UStaff>(basic);
}

void APThunder::BeginPlay()
{
	Super::BeginPlay();

}

void APThunder::Tick(float dt)
{
	Super::Tick(dt);


	if ((GetSprite()->GetPlaybackPosition()/GetSprite()->GetFlipbook()->GetTotalDuration()) >= 0.9f)
	{
		GetWorld()->DestroyActor(this);
	}
}

void APThunder::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->GetDamage(Basic->GetData().Damage);
	}
}

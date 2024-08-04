// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PShoes.h"
#include "System/GMB.h"
#include "Attacks/Basic/Shoes.h"
#include "GameObject/Enemy.h"
#include "PaperFlipbookComponent.h"

UShoes* APShoes::Basic;

APShoes::APShoes()
{
	PrimaryActorTick.bCanEverTick = true;
	str = TEXT("Shoes");
}

void APShoes::SetBasic(UBasic* basic)
{
	Basic = Cast<UShoes>(basic);
}

void APShoes::BeginPlay()
{
	Super::BeginPlay();


	Timer = 0.0f;
}

void APShoes::Tick(float dt)
{
	Super::Tick(dt);
	Timer += dt;
	if (Timer >= Basic->GetData().Duration)
	{
		SetActive(false);
	}
}

void APShoes::OnEnable()
{
	Super::OnEnable();
	GetSprite()->SetPlaybackPosition(0, false);
	Timer = 0.0f;
}

void APShoes::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->SetArmorDamaged();
	}
}

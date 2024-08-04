// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles.h"
#include "Components/CapsuleComponent.h"
#include "GameObject/Enemy.h"
#include "PaperFlipbookComponent.h"
#include "System/GMB.h"
#include "EnemyProjectiles.h"
#include "HitEffect.h"
#include "System/AIC.h"
#include "Attacks/Basic/Basic.h"


AProjectiles::AProjectiles()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Projectile"));
	Deletable = false;
	CollisionProfileName = TEXT("Projectile");

	static ConstructorHelpers::FClassFinder<AHitEffect> hiteffect(TEXT("/Script/Engine.Blueprint'/Game/Assets/Blueprints/GameObjects/Effect/BP_HitEffect.BP_HitEffect_C'"));
	HitEffect = hiteffect.Class;

}

void AProjectiles::SetBasic(UBasic* basic)
{

}

void AProjectiles::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Projectile"));
	UnPossessed();
	Controller = NewObject<AAIC>(this);
	Controller->Possess(this);
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AProjectiles::OnOverlap);

	
	
}

void AProjectiles::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		int32 rand = FMath::Rand() % 3;
		switch (rand)
		{
		case 0:
			Managers->Sound->PlaySfx(TEXT("Hit1"));
			break;

		case 1:
			Managers->Sound->PlaySfx(TEXT("Hit2"));
			break;

		case 2:
			Managers->Sound->PlaySfx(TEXT("Hit3"));
			break;
		}

		Managers->GetPoolManager<AHitEffect>()->Get(HitEffect, GetActorLocation());
		
		
	}

	if (Deletable)
	{
		if (AEnemyProjectiles* ebullet = Cast<AEnemyProjectiles>(OtherActor))
		{

			ebullet->SetActive(false);
		}
	}
}

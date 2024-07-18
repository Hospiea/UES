// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles.h"
#include "Components/CapsuleComponent.h"
#include "GameObject/Enemy.h"
#include "PaperFlipbookComponent.h"

AProjectiles::AProjectiles()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Projectile"));
}

void AProjectiles::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AProjectiles::OnOverlap);
}

void AProjectiles::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		enemy->GetSprite()->SetSpriteColor(FLinearColor::Red);
	}
}

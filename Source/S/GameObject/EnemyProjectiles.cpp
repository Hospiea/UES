// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/EnemyProjectiles.h"
#include "Components/CapsuleComponent.h"
#include "System/AIC.h"
#include "GameObject/Projectiles.h"
#include "GameObject/Player/User.h"

AEnemyProjectiles::AEnemyProjectiles()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("EnemyProjectile"));
}

void AEnemyProjectiles::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("EnemyProjectile"));
	UnPossessed();
	Controller = NewObject<AAIC>(this);
	Controller->Possess(this);
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemyProjectiles::OnOverlap);

}

void AEnemyProjectiles::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AProjectiles* pro = Cast<AProjectiles>(OtherActor))
	{
		if (pro->IsDeletable())
		{
			SetActive(false);
		}
	}

	else if (AUser* user = Cast<AUser>(OtherActor))
	{
		user->GetDamage(5);
		SetActive(false);
	}
}

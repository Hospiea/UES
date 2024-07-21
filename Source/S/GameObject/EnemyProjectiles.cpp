// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/EnemyProjectiles.h"
#include "Components/CapsuleComponent.h"
#include "System/AIC.h"

AEnemyProjectiles::AEnemyProjectiles()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("EnemyProjectile"));
}

void AEnemyProjectiles::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("EnemyProjectile"));
	Controller = NewObject<AAIC>(this);
	Controller->UnPossess();
	Controller->Possess(this);
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemyProjectiles::OnOverlap);

}

void AEnemyProjectiles::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

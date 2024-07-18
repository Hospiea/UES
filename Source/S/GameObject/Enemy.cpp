// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Enemy.h"
#include "Components/CapsuleComponent.h"
#include "GameObject/Player/User.h"
#include "System/GMB.h"
#include "System/AIC.h"

AEnemy::AEnemy()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Enemy"));
	AIController = CreateEditorOnlyDefaultSubobject<AAIC>(TEXT("Controller"));
	
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Enemy"));
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlap);
	AIController->Possess(this);
	Target = Managers->Game->Player;
}

void AEnemy::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

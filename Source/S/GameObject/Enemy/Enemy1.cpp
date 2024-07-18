// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Enemy/Enemy1.h"
#include "GameObject/Player/User.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemy1::AEnemy1()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemy1::Tick(float dt)
{
	Super::Tick(dt);
	FVector Location = Target->GetActorLocation() - GetActorLocation();
	Location.Normalize();
	
	FVector2D Dir = FVector2D(Location.X, Location.Z);
	Dir *= 30.0f;

	GetCharacterMovement()->Velocity = FVector(Dir.X, 0.0f, Dir.Y);
}

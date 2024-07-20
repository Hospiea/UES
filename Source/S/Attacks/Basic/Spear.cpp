// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Spear.h"
#include "Data/WeaponAsset.h"
#include "GameObject/Projectiles/PSpear.h"
#include "GameObject/Player/User.h"
#include "GameFramework/CharacterMovementComponent.h"

void USpear::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Spear"];
}

void USpear::BasicAttack(const FVector2D& Dir)
{
	Super::BasicAttack(Dir);
	APSpear* temp = World->SpawnActor<APSpear>(WeaponClass, SpawnLocation, FRotator(Angle -90.0f, 0.0f, 0.0f));
	FVector Vel = temp->GetActorLocation() - User->GetActorLocation();
	Vel.Normalize();
	Vel *= temp->GetData().Speed;
	temp->GetCharacterMovement()->Velocity = Vel * User->GetStats().ProjectileSpeed;
	temp->SetLifeSpan(temp->GetData().Duration * User->GetStats().ProjectileDuration);
}

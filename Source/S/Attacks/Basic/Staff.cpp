// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Staff.h"
#include "Data/WeaponAsset.h"
#include "GameObject/Projectiles/PThunder.h"
#include "GameObject/Player/User.h"
#include "GameFramework/CharacterMovementComponent.h"

void UStaff::Init()
{
	WeaponClass = Weapons->Weapons["Staff"];

}


void UStaff::BasicAttack(const FVector2D& Dir)
{
	Super::BasicAttack(Dir);
	APThunder* temp = World->SpawnActor<APThunder>(WeaponClass, SpawnLocation, FRotator(0.0f, 0.0f, 0.0f));
	
}
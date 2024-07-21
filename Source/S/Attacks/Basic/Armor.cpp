// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Armor.h"
#include "Data/WeaponAsset.h"
#include "GameObject/Player/User.h"
#include "GameObject/Projectiles/PArmor.h"
#include "Components/Center.h"
#include "GameObject/Projectiles.h"

void UArmor::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Armor"];
	SpawnLocation = User->GetActorLocation();

	if (Data == nullptr)
		Init();

	APArmor* temp = World->SpawnActor<APArmor>(WeaponClass, SpawnLocation, FRotator(0.0f, 0.0f, 0.0f));
	temp->AttachToComponent(User->GetCenter(), FAttachmentTransformRules::KeepWorldTransform);
}

void UArmor::BasicAttack(const FVector2D& Dir)
{
	
}

void UArmor::SetWeaponData()
{
	Super::SetWeaponData();

}

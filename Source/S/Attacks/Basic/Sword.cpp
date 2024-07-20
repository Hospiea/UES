// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Sword.h"
#include "GameObject/Projectiles/PSword.h"
#include "GameObject/Player/User.h"
#include "Components/Center.h"
#include "Data/WeaponAsset.h"

WeaponData APSword::Data;

USword::USword(const FObjectInitializer& Init)
	:Super(Init)
{

}

void USword::Init()
{
	WeaponClass = Weapons->Weapons["Sword"];
	
}

void USword::BasicAttack(const FVector2D& Dir)
{
	Super::BasicAttack(Dir);
	APSword* temp = World->SpawnActor<APSword>(WeaponClass, SpawnLocation, FRotator(Angle, 0.0f, 0.0f));
	temp->AttachToComponent(User->GetCenter(), FAttachmentTransformRules::KeepWorldTransform);
	temp->SetLifeSpan(temp->GetData().Duration * User->GetStats().ProjectileDuration);
}

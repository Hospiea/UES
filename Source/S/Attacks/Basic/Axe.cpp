// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Axe.h"
#include "GameObject/Projectiles/PAxe.h"
#include "GameObject/Player/User.h"
#include "Components/Center.h"
#include "Data/WeaponAsset.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "System/GMB.h"


void UAxe::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Axe"];
}

void UAxe::BasicAttack(const FVector2D& Dir)
{
	Super::BasicAttack(Dir);
	APAxe* temp = World->SpawnActor<APAxe>(WeaponClass, SpawnLocation, FRotator(Angle, 0.0f, 0.0f));
	FVector Vel = temp->GetActorLocation() - User->GetActorLocation();
	Vel.Normalize();
	Vel *= temp->GetData().Speed;
	temp->GetCharacterMovement()->Velocity = Vel * User->GetStats().ProjectileSpeed;
	temp->SetLifeSpan(temp->GetData().Duration * User->GetStats().ProjectileDuration);

}

void UAxe::SetWeaponData()
{
	FName str = TEXT("Axe");

	Data->Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage[APAxe::Level];
	Data->Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate[APAxe::Level];
	Data->Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range[APAxe::Level];
	Data->Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration[APAxe::Level];
	Data->Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed[APAxe::Level];
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Axe.h"
#include "GameObject/Projectiles/PAxe.h"
#include "GameObject/Player/User.h"
#include "Components/Center.h"
#include "Data/WeaponAsset.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "System/GMB.h"


UAxe::UAxe(const FObjectInitializer& Init)
	:Super(Init)
{
	APAxe::Basic = this;
}

void UAxe::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Axe"];
	SetWeaponData();
}

void UAxe::BasicAttack(const FVector2D& Dir)
{
	//Super::BasicAttack(Dir);
	SpawnLocation = User->GetActorLocation();
	APAxe* temp = World->SpawnActor<APAxe>(WeaponClass, SpawnLocation, FRotator(Angle, 0.0f, 0.0f));
	FVector Vel = FVector(Dir.X, temp->GetActorLocation().Y, Dir.Y) - temp->GetActorLocation();
	Vel.Normalize();
	Vel *= Data.Speed;
	temp->GetCharacterMovement()->Velocity = Vel * User->GetStats().ProjectileSpeed;
	temp->SetLifeSpan(Data.Duration * User->GetStats().ProjectileDuration);

}

void UAxe::SetWeaponData()
{
	FName str = TEXT("Axe");


	Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
	Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
	Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
	Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
	Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Negative.h"
#include "Data/WeaponAsset.h"
#include "GameObject/Player/User.h"
#include "System/GMB.h"
#include "GameObject/Projectiles/PNegative.h"
#include "GameFramework/CharacterMovementComponent.h"

UNegative::UNegative(const FObjectInitializer& Init)
	:Super(Init)
{
	APNegative::Basic = this;
}

void UNegative::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Negative"];
	SetWeaponData();
}

void UNegative::BasicAttack(const FVector2D& Dir)
{
	SpawnLocation = User->GetActorLocation();
	APNegative* temp = Managers->GetPoolManager<APNegative>()->Get(WeaponClass, SpawnLocation, FRotator(Angle - 90.0f, 0.0f, 0.0f));
	FVector Vel = FVector(Dir.X, temp->GetActorLocation().Y, Dir.Y) - temp->GetActorLocation();
	Vel.Normalize();
	Vel *= Data.Speed;
	temp->GetCharacterMovement()->Velocity = Vel * User->GetStats().ProjectileSpeed;
	temp->Span(Data.Duration * User->GetStats().ProjectileDuration);


	float angle = FMath::Atan2(Vel.Z, Vel.X);
	angle = FMath::RadiansToDegrees(angle);
	temp->SetActorRotation(FRotator(angle - 90.0f, 0.0f, 0.0f));

}

void UNegative::SetWeaponData()
{
	Super::SetWeaponData();
	FName str = TEXT("Negative");

	Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
	Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
	Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
	Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
	Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Spear.h"
#include "Data/WeaponAsset.h"
#include "GameObject/Projectiles/PSpear.h"
#include "GameObject/Player/User.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "System/GMB.h"

void USpear::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Spear"];
}

void USpear::BasicAttack(const FVector2D& Dir)
{
	//Super::BasicAttack(Dir);
	SpawnLocation = User->GetActorLocation();
	APSpear* temp = World->SpawnActor<APSpear>(WeaponClass, SpawnLocation, FRotator(Angle -90.0f, 0.0f, 0.0f));
	FVector Vel = FVector(Dir.X, temp->GetActorLocation().Y, Dir.Y) - temp->GetActorLocation();
	Vel.Normalize();
	Vel *= temp->GetData().Speed;
	temp->GetCharacterMovement()->Velocity = Vel * User->GetStats().ProjectileSpeed;
	temp->SetLifeSpan(temp->GetData().Duration * User->GetStats().ProjectileDuration);


	float angle = FMath::Atan2(Vel.Z, Vel.X);
	angle = FMath::RadiansToDegrees(angle);
	temp->SetActorRotation(FRotator(angle - 90.0f, 0.0f, 0.0f));
	
}

void USpear::SetWeaponData()
{
	FName str = TEXT("Spear");


	Data->Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
	Data->Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
	Data->Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
	Data->Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
	Data->Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
}

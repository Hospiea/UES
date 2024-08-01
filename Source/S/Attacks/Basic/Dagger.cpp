// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Dagger.h"
#include "GameObject/Projectiles/PDagger.h"
#include "Data/WeaponAsset.h"
#include "System/GMB.h"
#include "GameObject/Player/User.h"
#include "GameFramework/CharacterMovementComponent.h"

UDagger::UDagger(const FObjectInitializer& Init)
	:Super(Init)
{
	APDagger::Basic = this;
}

void UDagger::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Dagger"];
	SetWeaponData();
}

void UDagger::BasicAttack(const FVector2D& Dir)
{
	SpawnLocation = User->GetActorLocation();
	//APSpear* temp = World->SpawnActor<APSpear>(WeaponClass, SpawnLocation, FRotator(Angle -90.0f, 0.0f, 0.0f));
	APDagger* temp = Managers->GetPoolManager<APDagger>()->Get(WeaponClass, SpawnLocation, FRotator(Angle - 90.0f, 0.0f, 0.0f));
	FVector Vel = FVector(Dir.X, temp->GetActorLocation().Y, Dir.Y) - temp->GetActorLocation();
	Vel.Normalize();
	Vel *= Data.Speed;
	temp->GetCharacterMovement()->Velocity = Vel * User->GetStats().ProjectileSpeed;
	temp->Span(Data.Duration * User->GetStats().ProjectileDuration);


	float angle = FMath::Atan2(Vel.Z, Vel.X);
	angle = FMath::RadiansToDegrees(angle);
	temp->SetActorRotation(FRotator(angle - 90.0f, 0.0f, 0.0f));
}

void UDagger::SetWeaponData()
{
	FName str = TEXT("Dagger");

	Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
	Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
	Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
	Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
	Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
}

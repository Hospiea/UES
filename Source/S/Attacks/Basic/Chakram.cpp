// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Chakram.h"
#include "GameObject/Projectiles/PChakram.h"
#include "Data/WeaponAsset.h"
#include "GameObject/Player/User.h"
#include "System/GMB.h"
#include "GameFramework/CharacterMovementComponent.h"

UChakram::UChakram(const FObjectInitializer& Init)
	:Super(Init)
{
	APChakram::Basic = this;
}

void UChakram::Init()
{
	Super::Init();
	WeaponClass = Weapons->Weapons["Chakram"];
	SetWeaponData();
}

void UChakram::BasicAttack(const FVector2D& Dir)
{
	FVector2D NewDir = Dir.GetSafeNormal();
	NewDir *= 50.0f;
	SpawnLocation = User->GetActorLocation() + FVector(NewDir.X, 0.0f, NewDir.Y);
	FVector Base = FVector::ForwardVector;

	FVector NormalizedSpawnLocation = FVector(NewDir.X, 0.0f, NewDir.Y).GetSafeNormal();
	FVector NormalizedBase = Base.GetSafeNormal();
	float CosineAngle = FVector::DotProduct(NormalizedSpawnLocation, NormalizedBase);
	Angle = FMath::RadiansToDegrees(FMath::Acos(CosineAngle));


	FVector CrossProduct = FVector::CrossProduct(NormalizedSpawnLocation, NormalizedBase);
	if (CrossProduct.Y < 0)
		Angle = -Angle;


	SpawnLocation = User->GetActorLocation();
	APChakram* temp = World->SpawnActor<APChakram>(WeaponClass, SpawnLocation, FRotator(Angle - 90.0f, 0.0f, 0.0f));
	FVector Vel = FVector(Dir.X, temp->GetActorLocation().Y, Dir.Y) - temp->GetActorLocation();
	Vel.Normalize();
	Vel *= Data.Speed;
	temp->GetCharacterMovement()->Velocity = Vel * User->GetStats().ProjectileSpeed;
	temp->SetLifeSpan(Data.Duration * User->GetStats().ProjectileDuration);
	

}

void UChakram::SetWeaponData()
{
	FName str = TEXT("Chakram");


	Data.Damage = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Damage;
	Data.Rate = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Rate;
	Data.Range = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Range;
	Data.Duration = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Duration;
	Data.Speed = Managers->Data->WeaponData->FindRow<FWeaponData>(str, TEXT(""))->Speed;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Basic.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameObject/Player/User.h"
#include "System/GMB.h"
#include "Data/WeaponAsset.h"


UBasic::UBasic(const FObjectInitializer& Initializer)
	:Super(Initializer),
	Level(0)
{
	static ConstructorHelpers::FObjectFinder<UWeaponAsset> weapons(TEXT("/Script/S.WeaponAsset'/Game/Assets/Data/Weapons.Weapons'"));
	Weapons = weapons.Object;
	Init();
}

UBasic::~UBasic()
{

}

void UBasic::BasicAttack(const FVector2D& Dir)
{
	FVector2D NewDir = Dir * 50.0f;
	SpawnLocation = User->GetActorLocation() + FVector(NewDir.X, 0.0f, NewDir.Y);
	FVector Base = FVector::ForwardVector;

	FVector NormalizedSpawnLocation = FVector(NewDir.X, 0.0f, NewDir.Y).GetSafeNormal();
	FVector NormalizedBase = Base.GetSafeNormal();
	float CosineAngle = FVector::DotProduct(NormalizedSpawnLocation, NormalizedBase);
	Angle = FMath::RadiansToDegrees(FMath::Acos(CosineAngle));


	FVector CrossProduct = FVector::CrossProduct(NormalizedSpawnLocation, NormalizedBase);
	if (CrossProduct.Y < 0)
		Angle = -Angle;

}

void UBasic::Init()
{

}

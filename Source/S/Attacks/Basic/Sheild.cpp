// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Sheild.h"
#include "GameObject/Projectiles/PSheild.h"
#include "GameObject/Player/User.h"
#include "Components/Center.h"
#include "Data/WeaponAsset.h"


USheild::USheild(const FObjectInitializer& Init)
	:Super(Init)
{
	APSheild::Basic = this;
}

void USheild::Init()
{
	Super::Init();
	SetWeaponData();
	WeaponClass = Weapons->Weapons["Sheild"];
	SpawnLocation = User->GetActorLocation() + FVector(50.0f, 0.0f, 0.0f);
	FVector Base = FVector::ForwardVector;


	FVector NormalizedBase = Base.GetSafeNormal();
	float CosineAngle = FVector::DotProduct(SpawnLocation, NormalizedBase);
	Angle = FMath::RadiansToDegrees(FMath::Acos(CosineAngle));


	FVector CrossProduct = FVector::CrossProduct(SpawnLocation, NormalizedBase);
	if (CrossProduct.Y < 0)
		Angle = -Angle;



	APSheild* temp = World->SpawnActor<APSheild>(WeaponClass, SpawnLocation, FRotator(Angle, 0.0f, 0.0f));
	temp->AttachToComponent(User->GetCenter(), FAttachmentTransformRules::KeepWorldTransform);
}

void USheild::BasicAttack(const FVector2D& Dir)
{
	
}

void USheild::SetWeaponData()
{
	Super::SetWeaponData();

}

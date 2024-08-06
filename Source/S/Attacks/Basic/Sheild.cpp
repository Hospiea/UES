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
	counter = 0;
}

void USheild::Init()
{
	Super::Init();
	SetWeaponData();
	WeaponClass = Weapons->Weapons["Sheild"];

	++counter;


	for (int i = 0; i < Shields.Num(); ++i)
	{
		GetWorld()->DestroyActor(Shields[i]);
	}

	Shields.Empty();

	
	FVector Base = FVector::ForwardVector;

	TArray<FVector> Points;
	



	switch (counter)
	{
	case 1:
	{
		auto c1 = User->GetActorLocation() + FVector(50.0f, 0.0f, 0.0f);
		Points.Push(c1);
		break;
	}
		

	case 2:
	{
		auto c1 = User->GetActorLocation() + FVector(-50.0f, 0.0f, 0.0f);
		auto c2 = User->GetActorLocation() + FVector(50.0f, 0.0f, 0.0f);
		Points.Push(c1);
		Points.Push(c2);
		break;
	}
		

	case 3:
	{
		auto c1 = User->GetActorLocation() + FVector(50.0f * FMath::Cos(FMath::DegreesToRadians(0.0f)), 0.0f, 50.0f * FMath::Sin(FMath::DegreesToRadians(0.0f)));
		auto c2 = User->GetActorLocation() + FVector(50.0f * FMath::Cos(FMath::DegreesToRadians(120.0f)), 0.0f, 50.0f * FMath::Sin(FMath::DegreesToRadians(120.0f)));
		auto c3 = User->GetActorLocation() + FVector(50.0f * FMath::Cos(FMath::DegreesToRadians(240.0f)), 0.0f, 50.0f * FMath::Sin(FMath::DegreesToRadians(240.0f)));

		Points.Push(c1);
		Points.Push(c2);
		Points.Push(c3);
		break;
	}
		

	case 4:
	{
		auto c1 = User->GetActorLocation() + FVector(50.0f, 0.0f, 0.0f);
		auto c2 = User->GetActorLocation() + FVector(-50.0f, 0.0f, 0.0f);
		auto c3 = User->GetActorLocation() + FVector(0.0f, 0.0f, -50.0f);
		auto c4 = User->GetActorLocation() + FVector(0.0f, 0.0f, 50.0f);
		Points.Push(c1);
		Points.Push(c2);
		Points.Push(c3);
		Points.Push(c4);
		break;
	}
		

	case 5:
	{
		auto c1 = User->GetActorLocation() + FVector(50.0f * FMath::Cos(FMath::DegreesToRadians(0.0f)), 0.0f, 50.0f * FMath::Sin(FMath::DegreesToRadians(0.0f)));
		auto c2 = User->GetActorLocation() + FVector(50.0f * FMath::Cos(FMath::DegreesToRadians(72.0f)), 0.0f, 50.0f * FMath::Sin(FMath::DegreesToRadians(72.0f)));
		auto c3 = User->GetActorLocation() + FVector(50.0f * FMath::Cos(FMath::DegreesToRadians(144.0f)), 0.0f, 50.0f * FMath::Sin(FMath::DegreesToRadians(144.0f)));
		auto c4 = User->GetActorLocation() + FVector(50.0f * FMath::Cos(FMath::DegreesToRadians(216.0f)), 0.0f, 50.0f * FMath::Sin(FMath::DegreesToRadians(216.0f)));
		auto c5 = User->GetActorLocation() + FVector(50.0f * FMath::Cos(FMath::DegreesToRadians(288.0f)), 0.0f, 50.0f * FMath::Sin(FMath::DegreesToRadians(288.0f)));

		Points.Push(c1);
		Points.Push(c2);
		Points.Push(c3);
		Points.Push(c4);
		Points.Push(c5);
		break;
	}
		
	}


	for (int i = 0; i < Points.Num(); ++i)
	{
		
		FVector NormalizedBase = Base.GetSafeNormal();
		float CosineAngle = FVector::DotProduct(SpawnLocation, NormalizedBase);
		Angle = FMath::RadiansToDegrees(FMath::Acos(CosineAngle));


		FVector CrossProduct = FVector::CrossProduct(SpawnLocation, NormalizedBase);
		if (CrossProduct.Y < 0)
			Angle = -Angle;


		APSheild* temp = World->SpawnActor<APSheild>(WeaponClass, Points[i], FRotator(Angle, 0.0f, 0.0f));
		temp->AttachToComponent(User->GetCenter(), FAttachmentTransformRules::KeepWorldTransform);
		Shields.Push(temp);
	}
	

}

void USheild::BasicAttack(const FVector2D& Dir)
{
	
}

void USheild::SetWeaponData()
{
	Super::SetWeaponData();

}

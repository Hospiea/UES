// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Sword.h"
#include "GameObject/Projectiles/PSword.h"
#include "GameObject/Player/User.h"
#include "Components/Center.h"
#include "Kismet/KismetMathLibrary.h"

USword::USword()
{
	static ConstructorHelpers::FClassFinder<APSword> sword(TEXT("/Script/Engine.Blueprint'/Game/Assets/Blueprints/GameObjects/Projectiles/Basic/BP_PSword.BP_PSword_C'"));
	SwordClass = sword.Class;
}

void USword::BasicAttack(const FVector2D& Dir)
{
	Super::BasicAttack(Dir);

	FVector2D NewDir = Dir * 50.0f;
	FVector SpawnLocation = User->GetActorLocation() + FVector(NewDir.X, 0.0f, NewDir.Y);
	FVector Base = FVector::ForwardVector;

	FVector NormalizedSpawnLocation = FVector(NewDir.X, 0.0f, NewDir.Y).GetSafeNormal();
	FVector NormalizedBase = Base.GetSafeNormal();
	float CosineAngle = FVector::DotProduct(NormalizedSpawnLocation, NormalizedBase);
	float Angle = FMath::RadiansToDegrees(FMath::Acos(CosineAngle));


	FVector CrossProduct = FVector::CrossProduct(NormalizedSpawnLocation, NormalizedBase);
	if (CrossProduct.Y < 0)
		Angle = -Angle;

		
	APSword* temp = World->SpawnActor<APSword>(SwordClass, SpawnLocation, FRotator(Angle, 0.0f, 0.0f));
	temp->AttachToComponent(User->GetCenter(), FAttachmentTransformRules::KeepWorldTransform);
	temp->SetLifeSpan(0.15f);
}

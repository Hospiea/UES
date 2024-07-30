// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PChakramBody.h"
#include "GameObject/Projectiles/PChakram.h"
#include "System/GMB.h"

APChakramBody::APChakramBody()
	:Super(),
	Timer(0.0f)
{
	PrimaryActorTick.bCanEverTick = true;
}

void APChakramBody::Tick(float dt)
{
	Super::Tick(dt);
	if (!Center || Timer >= 3.14f || Timer <= -3.14f)
		GetWorld()->DestroyActor(this);

	if (bIsRight)
		Timer += dt * RotateSpeed;

	else
		Timer -= dt * RotateSpeed;

	FVector ToAngle = Managers->Game->Player->GetActorLocation() - Center->GetActorLocation();
	float Angle = FMath::Atan2(ToAngle.Z, ToAngle.X);
	FVector Location = RotateRadius * FVector(FMath::Cos(Timer + Angle), 0.0f, FMath::Sin(Timer + Angle));
	Location += FVector(Center->GetActorLocation().X, 0.0f, Center->GetActorLocation().Z);
	SetActorLocation(Location);
}


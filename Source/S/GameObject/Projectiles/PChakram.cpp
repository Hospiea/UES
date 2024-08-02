// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PChakram.h"
#include "Components/SceneComponent.h"
#include "PChakramBody.h"
#include "Components/CapsuleComponent.h"

UChakram* APChakram::Basic;

APChakram::APChakram()
	:Super()
{
	str = TEXT("Chakram");
}

void APChakram::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Nothing"));
	Body1 = GetWorld()->SpawnActor<APChakramBody>(ChakramBodyClass, GetActorLocation(), GetActorRotation());
	Body2 = GetWorld()->SpawnActor<APChakramBody>(ChakramBodyClass, GetActorLocation(), GetActorRotation());

	Body1->SetCenter(this);
	Body1->SetRight(true);
	Body2->SetCenter(this);
	Body2->SetRight(false);
}

void APChakram::Tick(float dt)
{
	Super::Tick(dt);

}

void APChakram::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

}

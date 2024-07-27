// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles/PAxe.h"
#include "System/GMB.h"
#include "Attacks/Basic/Axe.h"

UAxe* APAxe::Basic;

APAxe::APAxe()
{
	str = TEXT("Axe");

}

void APAxe::SetBasic(UBasic* basic)
{
	Basic = Cast<UAxe>(basic);
}

void APAxe::BeginPlay()
{
	Super::BeginPlay();


}

void APAxe::Tick(float dt)
{
	Super::Tick(dt);
	AddActorLocalRotation(FRotator(dt*1000, 0.0f, 0.0f));
}

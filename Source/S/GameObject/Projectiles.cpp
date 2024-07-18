// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Projectiles.h"
#include "Components/CapsuleComponent.h"

AProjectiles::AProjectiles()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Projectile"));
}

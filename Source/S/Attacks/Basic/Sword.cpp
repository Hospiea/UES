// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Sword.h"
#include "GameObject/Projectiles/PSword.h"
#include "GameObject/Player/User.h"
#include "Components/Center.h"

USword::USword()
{
	static ConstructorHelpers::FClassFinder<APSword> sword(TEXT("/Script/Engine.Blueprint'/Game/Assets/Blueprints/GameObjects/Projectiles/Basic/BP_PSword.BP_PSword_C'"));
	SwordClass = sword.Class;
}

void USword::BasicAttack(const FVector2D& Dir)
{
	Super::BasicAttack(Dir);

	FVector2D NewDir = Dir * 30.0f;
	auto temp = World->SpawnActor<APSword>(SwordClass, User->GetActorLocation() + FVector(NewDir.X, 0.0f, NewDir.Y), FRotator(0.0f, 0.0f, 0.0f));

	temp->AttachToComponent(User->GetCenter(), FAttachmentTransformRules::KeepWorldTransform);
}

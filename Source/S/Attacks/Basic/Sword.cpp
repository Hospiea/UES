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

void USword::BasicAttack()
{
	Super::BasicAttack();
	auto temp = World->SpawnActor<APSword>(SwordClass, User->GetActorLocation() + FVector(30.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	
	temp->AttachToComponent(User->GetCenter(), FAttachmentTransformRules::KeepWorldTransform);
}

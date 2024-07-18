// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AnimationComponent.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameObject/GameObjects.h"
#include "GameObject/Enemy.h"

// Sets default values for this component's properties
UAnimationComponent::UAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAnimationComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!MovementComponent) return;
	if (AEnemy* enemy = Cast<AEnemy>(GetOwner()))
	{
		if (enemy->GetEnemyState() == AEnemy::EnemyState::KnockBacked)
			return;
	}

	if (MovementComponent->Velocity.X > 0.0f)
	{
		Sprite->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	}

	else if (MovementComponent->Velocity.X < 0.0f)
	{
		Sprite->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
	
}


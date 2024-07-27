// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AttackComponent.h"
#include "Attacks/Basic/Basic.h"
#include "Attacks/Basic/Staff.h"
#include "GameObject/Player/User.h"
#include "DetectComponent.h"
#include "GameObject/Enemy.h"
#include "GameObject/Projectiles.h"
#include "Attacks/Basic/Sheild.h"
#include "Attacks/Basic/Armor.h"
#include "Attacks/Basic/Shoes.h"
#include "Attacks/Basic/Sword.h"
#include "Attacks/Basic/Spear.h"


// Sets default values for this component's properties
UAttackComponent::UAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UAttackComponent::Init(UWorld* world)
{
	World = world;

	Attacks.Add(NewObject<USword>());
	Attacks[0]->SetWorld(world);
	Attacks[0]->SetPlayer(Cast<AUser>(GetOwner()));
	Attacks[0]->Init();

	

	Detection = Cast<AUser>(GetOwner())->GetDetectComponent();
}

void UAttackComponent::AddAttack(UBasic* attack)
{
	if (attack->IsPassive())
	{
		Passives.Add(attack);
		attack->SetWorld(World);
		attack->Init();
		attack->SetPlayer(Cast<AUser>(GetOwner()));
		if (Passives.Num() == MaxWeapon)
		{
			bPassiveMax = true;
		}
	}

	else
	{
		Attacks.Add(attack);
		attack->SetWorld(World);
		attack->Init();
		attack->SetPlayer(Cast<AUser>(GetOwner()));
		if (Attacks.Num() == MaxWeapon)
		{
			bWeaponMax = true;
		}
	}

	
}


// Called when the game starts
void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();	
}


// Called every frame
void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (Detection->GetDetectedEnemyNumber() == 0 || !Detection || Attacks.Num() == 0)
		return;

	for (int i = 0; i < Attacks.Num(); ++i)
	{
		for (auto& temp : Attacks)
		{
			temp->GetData().Timer += DeltaTime;
			if (temp->GetData().Timer >= temp->GetData().Rate)
			{
				auto enemy = Detection->GetClosetEnemy();
				if (enemy == nullptr) continue;
				FVector2D Dir = FVector2D(enemy->GetActorLocation().X, enemy->GetActorLocation().Z);
				temp->BasicAttack(Dir);
				temp->GetData().Timer = 0.0f;
			}
		}
	}
}


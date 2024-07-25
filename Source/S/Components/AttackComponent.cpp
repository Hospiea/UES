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


	Attacks.Add(NewObject<USword>());
	Attacks[0]->SetWorld(world);
	Attacks[0]->SetPlayer(Cast<AUser>(GetOwner()));
	Attacks[0]->Init();

	Attacks.Add(NewObject<USheild>());
	Attacks[1]->SetWorld(world);
	Attacks[1]->SetPlayer(Cast<AUser>(GetOwner()));
	Attacks[1]->Init();

	Attacks.Add(NewObject<UShoes>());
	Attacks[2]->SetWorld(world);
	Attacks[2]->SetPlayer(Cast<AUser>(GetOwner()));
	Attacks[2]->Init();

	Attacks.Add(NewObject<USpear>());
	Attacks[3]->SetWorld(world);
	Attacks[3]->SetPlayer(Cast<AUser>(GetOwner()));
	Attacks[3]->Init();

	Attacks.Add(NewObject<UStaff>());
	Attacks[4]->SetWorld(world);
	Attacks[4]->SetPlayer(Cast<AUser>(GetOwner()));
	Attacks[4]->Init();

	Detection = Cast<AUser>(GetOwner())->GetDetectComponent();
}


// Called when the game starts
void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	//Attacks.Add(NewObject<UStaff>(this));
	
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


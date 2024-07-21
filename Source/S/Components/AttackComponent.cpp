// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AttackComponent.h"
#include "Attacks/Basic/Basic.h"
#include "Attacks/Basic/Staff.h"
#include "GameObject/Player/User.h"
#include "DetectComponent.h"
#include "GameObject/Enemy.h"
#include "GameObject/Projectiles.h"


// Sets default values for this component's properties
UAttackComponent::UAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();
	
	Attacks.Add(NewObject<UStaff>(this));
	Attacks[0]->Init();
	Attacks[0]->SetWorld(GetWorld());
	Attacks[0]->SetPlayer(Cast<AUser>(GetOwner()));
	
	Detection = Cast<AUser>(GetOwner())->GetDetectComponent();
}


// Called every frame
void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Cyan, FString::Printf(TEXT("%d"), Detection->GetDetectedEnemyNumber()));

	if (Detection->GetDetectedEnemyNumber() == 0)
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


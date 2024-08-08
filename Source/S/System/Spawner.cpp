// Fill out your copyright notice in the Description page of Project Settings.


#include "System/Spawner.h"
#include "Data/EnemyAsset.h"
#include "GameObject/Enemy/Enemy1.h"
#include "GameObject/Enemy/Enemy2.h"
#include "GameObject/Enemy/Enemy3.h"
#include "GMB.h"
#include "GameObject/Player/User.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Timer = 0.0f;

	static ConstructorHelpers::FObjectFinder<UEnemyAsset> enemyclass(TEXT("/Script/S.EnemyAsset'/Game/Assets/Data/Enemies.Enemies'"));
	EnemyClasses = enemyclass.Object;
	
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	User = Managers->Game->Player;
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timer += DeltaTime;

	if (Timer > 0.5f)
	{
		Timer = 0.0f;
		++counter;

		float Pos = 0.0f;
		auto judge = FMath::RandBool();
		
		if (judge)
			Pos = 250.0f;

		else
			Pos = -250.0f;

		if(counter < 10)
			auto temp = Managers->GetPoolManager<AEnemy1>()->Get(EnemyClasses->Enemies["Enemy1"], FVector(Pos + User->GetActorLocation().X, 10.0f, -Pos + User->GetActorLocation().Z));

		else if (counter > 30)
		{
			auto temp = Managers->GetPoolManager<AEnemy1>()->Get(EnemyClasses->Enemies["Enemy1"], FVector(Pos + User->GetActorLocation().X, 10.0f, -Pos + User->GetActorLocation().Z));
			auto temp2 = Managers->GetPoolManager<AEnemy2>()->Get(EnemyClasses->Enemies["Enemy2"], FVector(-Pos + User->GetActorLocation().X, 10.0f, Pos + User->GetActorLocation().Z));
			auto temp3 = Managers->GetPoolManager<AEnemy3>()->Get(EnemyClasses->Enemies["Enemy3"], FVector(-Pos + User->GetActorLocation().X, 10.0f, -Pos + User->GetActorLocation().Z));
		}

		else if (counter < 20)
		{
			auto temp = Managers->GetPoolManager<AEnemy1>()->Get(EnemyClasses->Enemies["Enemy1"], FVector(Pos + User->GetActorLocation().X, 10.0f, -Pos + User->GetActorLocation().Z));
			auto temp3 = Managers->GetPoolManager<AEnemy3>()->Get(EnemyClasses->Enemies["Enemy3"], FVector(-Pos + User->GetActorLocation().X, 10.0f, -Pos + User->GetActorLocation().Z));
		}
		
	}
}


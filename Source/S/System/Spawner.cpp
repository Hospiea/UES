// Fill out your copyright notice in the Description page of Project Settings.


#include "System/Spawner.h"
#include "Data/EnemyAsset.h"
#include "GameObject/Enemy/Enemy1.h"
#include "GameObject/Enemy/Enemy2.h"
#include "GameObject/Enemy/Enemy3.h"
#include "GMB.h"

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
	
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timer += DeltaTime;

	if (Timer > 0.5f)
	{
		Timer = 0.0f;

		float Pos = 0.0f;
		auto judge = FMath::RandBool();
		
		if (judge)
			Pos = 250.0f;

		else
			Pos = -250.0f;




		//auto temp = Get<AEnemy1>(EnemyClasses->Enemies["Enemy1"], FVector(Pos, 10.0f, -Pos), FRotator::ZeroRotator);
		//auto temp2 = Get<AEnemy2>(EnemyClasses->Enemies["Enemy2"], FVector(-Pos, 10.0f, -Pos), FRotator::ZeroRotator);
		
		auto temp = Managers->GetPoolManager<AEnemy1>()->Get(EnemyClasses->Enemies["Enemy1"], FVector(Pos, 10.0f, -Pos));
		auto temp2 = Managers->GetPoolManager<AEnemy2>()->Get(EnemyClasses->Enemies["Enemy2"], FVector(-Pos, 10.0f, -Pos));
		auto temp3= Managers->GetPoolManager<AEnemy3>()->Get(EnemyClasses->Enemies["Enemy3"], FVector(-Pos, 10.0f, Pos));
	}
}


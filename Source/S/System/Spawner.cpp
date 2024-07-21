// Fill out your copyright notice in the Description page of Project Settings.


#include "System/Spawner.h"
#include "GameObject/Enemy/Enemy1.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Timer = 0.0f;

	static ConstructorHelpers::FClassFinder<AEnemy1> enemyclass(TEXT("/Script/Engine.Blueprint'/Game/Assets/Blueprints/GameObjects/Enemy/BP_Enemy1.BP_Enemy1_C'"));
	Enemy1Class = enemyclass.Class;
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

		auto temp = GetWorld()->SpawnActor<AEnemy1>(Enemy1Class, FVector(Pos, 10.0f, -Pos), FRotator::ZeroRotator);

	}
}


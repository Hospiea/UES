// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/EnemyProjectiles/EnemyRangeBase.h"

void AEnemyRangeBase::BeginPlay()
{
	Super::BeginPlay();
	Timer = 0.0f;
}

void AEnemyRangeBase::Tick(float dt)
{
	Super::Tick(dt);
	Timer += dt;

	if (Timer > 2.5f)
	{
		SetActive(false);
		Timer = 0.0f;
	}
}

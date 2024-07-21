// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/GameObjects.h"
#include "EnemyProjectiles.generated.h"

/**
 * 
 */
UCLASS()
class S_API AEnemyProjectiles : public AGameObjects
{
	GENERATED_BODY()

public:
	AEnemyProjectiles();


protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};

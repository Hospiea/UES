// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/GameObjects.h"
#include "Enemy.generated.h"

class AUser;
class AAIC;

UCLASS()
class S_API AEnemy : public AGameObjects
{
	GENERATED_BODY()

public:
	AEnemy();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY()
	TObjectPtr<AUser> Target;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AAIC> AIController;

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/GameObjects.h"
#include "Projectiles.generated.h"

USTRUCT()
struct FProjectileData
{
	GENERATED_BODY()

	float Damage;
	float Rate;
	float Range;
	float Speed;
	float Duration;
	float Timer;
};

class AHitEffect;
class UBasic;

UCLASS()
class S_API AProjectiles : public AGameObjects
{
	GENERATED_BODY()

public:
	AProjectiles();
	virtual void SetBasic(UBasic* basic);

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY()
	TSubclassOf<AHitEffect> HitEffect;

	bool Deletable;
	FName str;

};



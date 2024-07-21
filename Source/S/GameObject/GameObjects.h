// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Data/FlipbookAsset.h"
#include "GameObjects.generated.h"

class UAnimationComponent;

UCLASS()
class S_API AGameObjects : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	inline const bool& ActiveSelf() { return IsActive; }
	inline void SetActive(const bool& flag) { IsActive = flag; }
	AGameObjects();
	virtual void GetDamage(const float& value) {};

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	bool IsActive = true;

	UPROPERTY(VisibleAnywhere, Category = "Flipbook Assets")
	TObjectPtr<UFlipbookAsset> Flipbooks;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAnimationComponent> AnimationComponent;

	
};

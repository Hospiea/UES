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
	void SetActive(bool flag);
	virtual void OnEnable();
	virtual void OnDisable();
	AGameObjects();
	virtual void GetDamage(const float& value) {};
	void Span(const float& Timer);

protected:
	virtual void BeginPlay() override;
	inline static uint8 Order = 0;
	void SpanHelper();

	UPROPERTY()
	bool IsActive = true;

	UPROPERTY(VisibleAnywhere, Category = "Flipbook Assets")
	TObjectPtr<UFlipbookAsset> Flipbooks;


	UPROPERTY()
	FName CollisionProfileName;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/GameObjects.h"
#include "ExpOrb.generated.h"

class UFlipbookAsset;

UCLASS()
class S_API AExpOrb : public AGameObjects
{
	GENERATED_BODY()
	
public:
	AExpOrb();
	void SetExpLevel(const uint8& lv);
	void Grabbed();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;

	static TObjectPtr<UFlipbookAsset> ExpSprites;
	
	

	UPROPERTY()
	uint8 Lv;

	UPROPERTY()
	bool bIsGrabbed;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

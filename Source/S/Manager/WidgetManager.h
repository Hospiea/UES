// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WidgetManager.generated.h"

class UWidgetAsset;
class ULevelUpSkillSlot;

UCLASS()
class S_API AWidgetManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AWidgetManager();
	void LevelUp();
	void Pause();
	void RemovePopupWidget();
	inline TArray<TObjectPtr<UTexture2D>>& GetWeaponImages() { return WeaponImages; }
	inline TArray<TObjectPtr<UTexture2D>>& GetPassiveImages() { return PassiveImages; }
	void EndOpening();

protected:
	virtual void BeginPlay() override;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UUserWidget> CurrentWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UUserWidget> PopupWidget;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UWidgetAsset> Widgets;

	UPROPERTY()
	TArray<TObjectPtr<UTexture2D>> WeaponImages;

	UPROPERTY()
	TArray<TObjectPtr<UTexture2D>> PassiveImages;
};
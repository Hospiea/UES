// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LevelUpSkillSlot.generated.h"

class UImage;
class UTexture2D;
class UHorizontalBox;
class USlots;

UCLASS()
class S_API ULevelUpSkillSlot : public UUserWidget
{
	GENERATED_BODY()
	
public:
	ULevelUpSkillSlot(const FObjectInitializer& Init);


protected:
	virtual void NativeConstruct() override;



protected:
	TArray<TObjectPtr<USlots>> WeaponImages;
	TArray<TObjectPtr<USlots>> PassiveImages;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UHorizontalBox> Weapon_Frame_Box;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UHorizontalBox> Passive_Frame_Box;

	UPROPERTY()
	TSubclassOf<USlots> SlotClass;
};

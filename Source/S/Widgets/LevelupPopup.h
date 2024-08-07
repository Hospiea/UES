// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WidgetBase.h"
#include "LevelupPopup.generated.h"

class UButton;
class ULevelUpSkillSlot;
class ULevelUpSelectCard;

UCLASS()
class S_API ULevelupPopup : public UWidgetBase
{
	GENERATED_BODY()

public:


protected:
	virtual void NativeConstruct() override;


protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<ULevelUpSkillSlot> Skill_Slot;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> Button0;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button1;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button2;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<ULevelUpSelectCard> LVUP_Card_Button_0;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<ULevelUpSelectCard> LVUP_Card_Button_1;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<ULevelUpSelectCard> LVUP_Card_Button_2;

	UPROPERTY()
	TArray< TObjectPtr<ULevelUpSelectCard>> Cards;

	UFUNCTION()
	void OnClicked();

};

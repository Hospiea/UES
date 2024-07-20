// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WidgetBase.h"
#include "LevelupPopup.generated.h"

class UButton;

UCLASS()
class S_API ULevelupPopup : public UWidgetBase
{
	GENERATED_BODY()
	

protected:
	virtual void NativeConstruct() override;


protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> Button0;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button1;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button2;

	UFUNCTION()
	void OnClicked();
};

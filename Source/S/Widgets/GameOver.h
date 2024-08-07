// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WidgetBase.h"
#include "GameOver.generated.h"

class UButton;

UCLASS()
class S_API UGameOver : public UWidgetBase
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> B_Back_to_Main;

	UFUNCTION()
	void ToMain();
};

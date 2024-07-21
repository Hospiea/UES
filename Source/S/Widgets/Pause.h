// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WidgetBase.h"
#include "Pause.generated.h"

class UButton;


UCLASS()
class S_API UPause : public UWidgetBase
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& geo, float dt) override;

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> Button_Continue;


	UFUNCTION()
	void Resume();

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WidgetBase.h"
#include "HPBar.generated.h"

class UProgressBar;

UCLASS()
class S_API UHPBar : public UWidgetBase
{
	GENERATED_BODY()
	
public:
	void SetValue(const float& value);

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UProgressBar> HP_Bar;

};

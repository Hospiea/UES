// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WidgetBase.h"
#include "WidgetHUD.generated.h"

class UEXP;

UCLASS()
class S_API UWidgetHUD : public UWidgetBase
{
	GENERATED_BODY()
	
public:
	void SetPercent(const float& value);


	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UEXP> Exp;
};

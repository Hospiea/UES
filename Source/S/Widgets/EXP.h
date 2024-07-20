// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WidgetBase.h"
#include "EXP.generated.h"

class UProgressBar;

UCLASS()
class S_API UEXP : public UWidgetBase
{
	GENERATED_BODY()

public:
	inline TObjectPtr<UProgressBar>& GetExp() { return EXP; }
	
protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UProgressBar> EXP;
};

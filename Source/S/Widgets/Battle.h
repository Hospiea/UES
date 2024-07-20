// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Battle.generated.h"

class UTextBlock;
class UButton;
class UProgressBar;

UCLASS()
class S_API UBattle : public UUserWidget
{
	GENERATED_BODY()
	
public:

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Timer;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Money_Text;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> KillCount_Text;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> EXP_Gauge;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Battle.generated.h"

class UTextBlock;
class UButton;
class UProgressBar;
class AUser;

UCLASS()
class S_API UBattle : public UUserWidget
{
	GENERATED_BODY()
	
public:
	inline void SetPlayer(AUser* user) { User = user; }

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& geo, float dt) override;

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Timer;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Money_Text;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> KillCount_Text;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> EXP_Gauge;

	UPROPERTY()
	TObjectPtr<AUser> User;
};

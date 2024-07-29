// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WidgetBase.h"
#include "Pause.generated.h"

class UButton;
class UPauseCard;
class UCanvasPanel;
class UGridPanel;

UCLASS()
class S_API UPause : public UWidgetBase
{
	GENERATED_BODY()

public:
	UPause(const FObjectInitializer& Init);
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& geo, float dt) override;

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> Button_Continue;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCanvasPanel> Passive_Panel;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCanvasPanel> Weapon_Panel;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UGridPanel> Passive_Grid;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UGridPanel> Weapon_Grid;

	UPROPERTY()
	TArray<TObjectPtr<UPauseCard>> WeaponCards;

	UPROPERTY()
	TArray<TObjectPtr<UPauseCard>> PassiveCards;



	UFUNCTION()
	void Resume();

	UPROPERTY(VisibleAnywhere)
	TSubclassOf<UPauseCard> CardClass;

};

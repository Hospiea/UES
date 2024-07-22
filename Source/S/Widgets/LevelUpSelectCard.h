// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WidgetBase.h"
#include "LevelUpSelectCard.generated.h"

class UImage;
class UTexture2D;
class AUser;
class UBasic;
class UCanvasPanel;

UCLASS()
class S_API ULevelUpSelectCard : public UWidgetBase
{
	GENERATED_BODY()
	
public:
	ULevelUpSelectCard(const FObjectInitializer& Init);

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Skill_LV_Star;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCanvasPanel> Select_Card_Panel;
	
	
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	
	
	
	
	
	
	UPROPERTY()
	TObjectPtr<UTexture2D> Lv0;

	UPROPERTY()
	TObjectPtr<UTexture2D> Lv1;

	UPROPERTY()
	TObjectPtr<UTexture2D> Lv2;

	UPROPERTY()
	TObjectPtr<UTexture2D> Lv3;

	UPROPERTY()
	TObjectPtr<UTexture2D> Lv4;

	UPROPERTY()
	TObjectPtr<UTexture2D> Ult;

	UPROPERTY()
	TObjectPtr<AUser> User;

	UPROPERTY()
	TArray<TObjectPtr<UBasic>> Attacks;

	UBasic::AttackType CardType;
};

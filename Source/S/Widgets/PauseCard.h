// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseCard.generated.h"

class UTexture2D;
class UImage;

UCLASS()
class S_API UPauseCard : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPauseCard(const FObjectInitializer& Init);
	void SetImage(UTexture2D* texture);
	void SetLevel(const int32& lv);

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Item_Image;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Skill_Slot_Card;

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

};

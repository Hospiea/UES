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
	void SetImage(UTexture2D* texture);

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Item_Image;

};

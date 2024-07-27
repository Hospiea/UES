// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Slots.generated.h"

class UImage;
class UTexture2D;

UCLASS()
class S_API USlots : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetImage(const UTexture2D* image);
	

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Image;
};

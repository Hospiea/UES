// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Data/FlipbookAsset.h"
#include "GameObjects.generated.h"


UCLASS()
class S_API AGameObjects : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	AGameObjects();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Flipbook Assets")
	TObjectPtr<UFlipbookAsset> Flipbooks;
};

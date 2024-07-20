// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WidgetManager.generated.h"

class UWidgetAsset;

UCLASS()
class S_API AWidgetManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AWidgetManager();

protected:
	virtual void BeginPlay() override;




protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UUserWidget> CurrentWidget;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UWidgetAsset> Widgets;
};

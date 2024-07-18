// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "DataManager.h"
#include "GameManager.h"
#include "Manager.generated.h"


UCLASS()
class S_API UManager : public UEngineSubsystem
{
	GENERATED_BODY()
	

public:
	virtual ~UManager() override;
	
	GameManager* Game;
	UPROPERTY()
	TObjectPtr<UDataManager> Data;


protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;


};

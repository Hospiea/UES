// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "GameManager.h"
#include "Manager.generated.h"




UCLASS()
class S_API UManager : public UEngineSubsystem
{
	GENERATED_BODY()
	

public:
	GameManager* Game;


protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;


};

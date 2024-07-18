// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Manager/Manager.h"
#include "GMB.generated.h"

class ASpawner;

UCLASS()
class S_API AGMB : public AGameModeBase
{
	GENERATED_BODY()
	static AGMB* Instance;
public:
	AGMB();
	inline static const TObjectPtr<UManager>& GetManager() { return Instance->Manager; }

protected:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<ASpawner> Spawner;

	UPROPERTY()
	TObjectPtr<UManager> Manager;

};

#define Managers AGMB::GetManager()

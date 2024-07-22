// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "DataManager.h"
#include "GameManager.h"
#include "WidgetManager.h"
#include "PoolManager.h"
#include <memory>
#include <unordered_map>
#include "Manager.generated.h"

class APC;

UCLASS()
class S_API UManager : public UEngineSubsystem
{
	GENERATED_BODY()
	

public:
	virtual ~UManager() override;

	inline void SetWorld(UWorld* world) { World = world; }

	UPROPERTY()
	TObjectPtr<AWidgetManager> Widget;
	
	GameManager* Game;
	
	inline void PoolClear() { Pool.reset(); }
	

	template<typename T>
	PoolManager<T>* GetPoolManager()
	{
		if (Pool == nullptr)
		{
			Pool = std::make_shared<PoolManager<T>>();
			static_cast<PoolManager<T>*>(Pool.get())->SetWorld(World);
		}
			
		return static_cast<PoolManager<T>*>(Pool.get());
	}



	UPROPERTY()
	TObjectPtr<APC> Controller;

	UPROPERTY()
	TObjectPtr<UDataManager> Data;

	

protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UPROPERTY()
	UWorld* World;

private:
	std::shared_ptr<void> Pool;
};

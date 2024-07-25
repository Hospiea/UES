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
	
	inline void PoolClear() { PoolMap.Empty(); }

	//template<typename T>
	//PoolManager<T>* GetPoolManager()
	//{
	//	if (Pool == nullptr)
	//	{
	//		Pool = MakeShared<PoolManager<T>>();
	//		static_cast<PoolManager<T>*>(Pool.Get())->SetWorld(World);
	//	}
	//		
	//	return static_cast<PoolManager<T>*>(Pool.Get());
	//}

	template<typename T>
	PoolManager<T>* GetPoolManager()
	{
		UClass* Class = T::StaticClass();
		if (!PoolMap.Contains(Class))
		{
			TSharedPtr<PoolManager<T>> poolManager = MakeShared<PoolManager<T>>();
			poolManager->SetWorld(World);
			PoolMap.Add(Class, poolManager);
		}

		return static_cast<PoolManager<T>*>(PoolMap[Class].Get());
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
	TMap<UClass*, TSharedPtr<void>> PoolMap;

};

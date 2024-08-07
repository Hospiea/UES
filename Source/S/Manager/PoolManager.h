// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <type_traits>
#include <memory>
#include "GameObject/Enemy.h"
#include "GameObject/GameObjects.h"
#include "GameObject/Projectiles.h"

class UWorld;
class AEnemy;

class IPoolManager
{
public:
	virtual void ExecuteClear() = 0;
	virtual ~IPoolManager() = default;
};


template<typename T>
class S_API PoolManager : public IPoolManager
{
	static_assert(!std::is_base_of<T, AGameObjects>::value, "T must be derieved from AGameObjects");

public:
	PoolManager();
	virtual ~PoolManager();
	inline void SetWorld(UWorld* world) { World = world; }
	T* Get(UClass* Class, const FVector& Pos = FVector::ZeroVector, const FRotator& Rot = FRotator::ZeroRotator);
	void Clear();
	virtual void ExecuteClear() override { Clear(); }

private:
	TArray<TObjectPtr<T>> Pool;

	UWorld* World;

};

template<typename T>
inline PoolManager<T>::PoolManager()
{

}

template<typename T>
inline PoolManager<T>::~PoolManager()
{
}

template<typename T>
inline T* PoolManager<T>::Get(UClass* Class, const FVector& Pos, const FRotator& Rot)
{

	if (Pool.Num() == 0)
	{
		auto&& enemy = World->SpawnActor<T>(Class, Pos, Rot);
		Pool.Add(enemy);
		return enemy;
	}
	else
	{
		for (auto& temp : Pool)
		{
			if (!temp->ActiveSelf() && (temp->IsA(T::StaticClass()) || temp->IsA(Class)))
			{
				temp->SetActorLocationAndRotation(Pos, Rot);
				temp->T::SetActive(true);
				return temp;
			}
		}
		auto&& enemy = World->SpawnActor<T>(Class, Pos, Rot);
		Pool.Add(enemy);
		return enemy;
	}
}

template<typename T>
inline void PoolManager<T>::Clear()
{
	for (auto& temp : Pool)
	{
		World->DestroyActor(temp);
	}
	Pool.Empty();
}

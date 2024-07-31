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


template<typename T>
class S_API PoolManager
{
	static_assert(std::is_base_of<AGameObjects, T>::value, "T must be derieved from AGameObjects");

public:
	PoolManager();
	~PoolManager();
	inline void SetWorld(UWorld* world) { World = world; }
	T* Get(UClass* Class, const FVector& Pos = FVector::ZeroVector, const FRotator& Rot = FRotator::ZeroRotator);


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
		auto enemy = World->SpawnActor<T>(Class, Pos, Rot);
		Pool.Add(enemy);
		return enemy;
	}
	else
	{
		for (auto& temp : Pool)
		{
			if (!temp->AGameObjects::ActiveSelf() && (temp->IsA(T::StaticClass()) || temp->IsA(Class)))
			{
				temp->AGameObjects::SetActive(true);
				temp->AGameObjects::SetActorLocationAndRotation(Pos, Rot);
				return Cast<T>(temp);
			}
		}
		auto enemy = World->SpawnActor<T>(Class, Pos, Rot);
		Pool.Add(enemy);
		return enemy;
	}
}
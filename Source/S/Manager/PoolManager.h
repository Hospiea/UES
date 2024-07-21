// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <type_traits>
#include <memory>
#include "GameObject/Enemy.h"
#include "GameObject/GameObjects.h"
#include "GameObject/Projectiles.h"

class UWorld;

template<typename T>
class S_API PoolManager
{
	friend class UManager;
	PoolManager();
	~PoolManager();

public:
	inline void SetWorld(UWorld* world) { World = world; }
	T* Get();


private:
	T* CreateFunc();

	TArray<T*> Pool;

	TSubclassOf<T> Class;

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
inline T* PoolManager<T>::Get()
{
	if (Pool.Num() == 0)
		return CreateFunc();

	else
	{
		for (T* temp : Pool)
		{
			if (temp == nullptr)
			{
				Pool.Remove(temp);
				continue;
			}
				
			if (!temp->ActiveSelf())
			{
				return temp;
			}
		}

		return CreateFunc();
	}

	return nullptr;
}

template<typename T>
inline T* PoolManager<T>::CreateFunc()
{
	T* temp = World->SpawnActor<T>();
	Pool.Add(temp);
	return temp;
}

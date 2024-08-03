// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class AEnemy;
class UEnemyAsset;
class AUser;

UCLASS()
class S_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY()
	float Timer;

	UPROPERTY()
	TObjectPtr<UEnemyAsset> EnemyClasses;

	UPROPERTY()
	TArray<TObjectPtr<AEnemy>> EnemyPool;

	UPROPERTY()
	TObjectPtr<AUser> User;

private:
	template<typename T>
	T* Get(UClass* Class, const FVector& Pos, const FRotator& Rot);

};




#pragma region ObjectPoolTest
template<typename T>
inline T* ASpawner::Get(UClass* Class, const FVector& Pos, const FRotator& Rot)
{
	if (EnemyPool.Num() == 0)
	{
		auto enemy = GetWorld()->SpawnActor<T>(Class, Pos, Rot);
		EnemyPool.Add(enemy);
		return enemy;
	}
	else
	{
		for (auto& temp : EnemyPool)
		{
			if (!temp->ActiveSelf())
			{
				temp->SetActive(true);
				temp->SetActorLocationAndRotation(Pos, Rot);
				return Cast<T>(temp);
			}
		}
		auto enemy = GetWorld()->SpawnActor<T>(Class, Pos, Rot);
		EnemyPool.Add(enemy);
		return enemy;
	}
}
#pragma endregion
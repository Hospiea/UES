// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"

class UBasic;
class UDetectComponent;
class UWorld;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttackComponent();
	inline TArray<TObjectPtr<UBasic>>& GetAttackTypes() { return Attacks; }
	inline TArray<TObjectPtr<UBasic>>& GetPassiveTypes() { return Passives; }
	void Init(UWorld* world);
	void AddAttack(UBasic* attack);
	inline const bool& IsWeaponMax() { return bWeaponMax; }
	inline const bool& IsPassiveMax() { return bPassiveMax; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	const uint8 MaxWeapon = 6;

	bool bWeaponMax = false;
	bool bPassiveMax = false;

	UPROPERTY()
	TArray<TObjectPtr<UBasic>> Attacks;

	UPROPERTY()
	TArray<TObjectPtr<UBasic>> Passives;

	UPROPERTY()
	TObjectPtr<UDetectComponent> Detection;

	UPROPERTY()
	UWorld* World;
};

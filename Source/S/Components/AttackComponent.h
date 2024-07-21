// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"

class UBasic;
class UDetectComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	const uint8 MaxWeapon = 3;
	UPROPERTY()
	TArray<TObjectPtr<UBasic>> Attacks;

	TObjectPtr<UDetectComponent> Detection;
};

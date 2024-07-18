// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Interface/BasicAttack.h"
#include "Basic.generated.h"

class AUser;
class UWorld;

UCLASS()
class S_API UBasic : public UObject, public IBasicAttack
{
	GENERATED_BODY()
	
public:
	void BasicAttack() override {};
	inline void SetPlayer(AUser* user) 
	{ 
		User = user; 
	}
	inline void SetWorld(UWorld* world) { World = world; }


protected:
	UPROPERTY()
	TObjectPtr<AUser> User;

	UPROPERTY()
	TObjectPtr<UWorld> World;
};

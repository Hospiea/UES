// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Player/User.h"


class S_API GameManager
{
	GameManager();
	~GameManager();
	friend class UManager;

public:
	UPROPERTY()
	TObjectPtr<AUser> Player;

};

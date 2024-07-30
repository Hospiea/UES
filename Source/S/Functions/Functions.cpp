// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/Functions.h"
#include "Manager/Manager.h"

void UFunctions::PlayBgm(const FString& str)
{
	UManager* manager = GEngine->GetEngineSubsystem<UManager>();
	manager->Sound->PlayBgm(str);
}

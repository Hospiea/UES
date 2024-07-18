// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/DataManager.h"


UDataManager::UDataManager(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UDataTable> playerstats(TEXT("/Script/Engine.DataTable'/Game/Assets/Data/PlayerStats.PlayerStats'"));
	static ConstructorHelpers::FObjectFinder<UDataTable> enemystats(TEXT("/Script/Engine.DataTable'/Game/Assets/Data/EnemyStats.EnemyStats'"));
	static ConstructorHelpers::FObjectFinder<UDataTable> weapondata(TEXT("/Script/Engine.DataTable'/Game/Assets/Data/WeaponData.WeaponData'"));


	PlayerStats = playerstats.Object;
	EnemyStats = enemystats.Object;
	WeaponData = weapondata.Object;
}

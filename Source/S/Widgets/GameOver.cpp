// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/GameOver.h"
#include "Components/Button.h"
#include "System/GMB.h"

void UGameOver::NativeConstruct()
{
	Super::NativeConstruct();
	B_Back_to_Main->OnClicked.AddDynamic(this, &UGameOver::ToMain);
}

void UGameOver::ToMain()
{
	Managers->Widget->ClickToLobby();
}

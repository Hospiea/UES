// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/LevelupPopup.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "System/GMB.h"
#include "LevelUpSkillSlot.h"
#include "System/PC.h"

void ULevelupPopup::NativeConstruct()
{
	Super::NativeConstruct();
	Button0->OnClicked.AddDynamic(this, &ULevelupPopup::OnClicked);
	Button1->OnClicked.AddDynamic(this, &ULevelupPopup::OnClicked);
	Button2->OnClicked.AddDynamic(this, &ULevelupPopup::OnClicked);

}

void ULevelupPopup::OnClicked()
{
	Managers->Widget->RemovePopupWidget();
}

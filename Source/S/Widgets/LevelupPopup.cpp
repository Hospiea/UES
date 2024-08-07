// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/LevelupPopup.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "System/GMB.h"
#include "LevelUpSkillSlot.h"
#include "System/PC.h"
#include "LevelUpSelectCard.h"

void ULevelupPopup::NativeConstruct()
{
	Super::NativeConstruct();
	Button0->OnClicked.AddDynamic(this, &ULevelupPopup::OnClicked);
	Button1->OnClicked.AddDynamic(this, &ULevelupPopup::OnClicked);
	Button2->OnClicked.AddDynamic(this, &ULevelupPopup::OnClicked);

	Cards.Push(LVUP_Card_Button_0);
	Cards.Push(LVUP_Card_Button_1);
	Cards.Push(LVUP_Card_Button_2);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = i + 1; j < 3; ++j)
		{
			if (Cards[i]->IsSame(*Cards[j]))
			{
				Cards[j]->ReRoll();
				--i;
				break;
			}
		}
	}
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void ULevelupPopup::OnClicked()
{
	//Managers->Widget->RemovePopupWidget();
}

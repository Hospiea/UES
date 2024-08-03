// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Pause.h"
#include "Components/Button.h"
#include "PauseCard.h"
#include "System/GMB.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/CanvasPanel.h"
#include "Components/GridPanel.h"
#include "Components/GridSlot.h"
#include "Components/AttackComponent.h"
#include "Attacks/Basic/Basic.h"
#include "Kismet/GameplayStatics.h"

UPause::UPause(const FObjectInitializer& Init)
	:Super(Init)
{
	static ConstructorHelpers::FClassFinder<UPauseCard> pauseclass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Art/UI/UI_Pause/BP_Pause_Skill_Slot.BP_Pause_Skill_Slot_C'"));
	CardClass = pauseclass.Class;
}

void UPause::NativeConstruct()
{
	Super::NativeConstruct();
	Button_Continue->OnClicked.AddDynamic(this, &UPause::Resume);

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			auto temp = CreateWidget<UPauseCard>(GetOwningPlayer(), CardClass);
			temp->SetRenderOpacity(0.0f);
			auto slot = Passive_Grid->AddChildToGrid(temp);
			slot->SetColumn(j);
			slot->SetRow(i);
			PassiveCards.Add(temp);

			if (i == 0 && j == 0)
				slot->SetPadding(FMargin(FVector4f(0.0f, 0.0f, 30.0f, 14.0f)));
			
			else if(i==0 && j==1)
				slot->SetPadding(FMargin(FVector4f(15.0f, 0.0f, 15.0f, 14.0f)));

			else if (i == 0 && j == 2)
				slot->SetPadding(FMargin(FVector4f(30.0f, 0.0f, 15.0f, 14.0f)));

			else if (i == 1 && j == 0)
				slot->SetPadding(FMargin(FVector4f(0.0f, 14.0f, 30.0f, 0.0f)));

			else if (i == 1 && j == 1)
				slot->SetPadding(FMargin(FVector4f(15.0f, 14.0f, 15.0f, 0.0f)));

			else if (i == 1 && j == 2)
				slot->SetPadding(FMargin(FVector4f(30.0f, 14.0f, 0.0f, 0.0f)));
		}
	}

	for (int i = 0; i < Managers->Widget->GetPassiveImages().Num(); ++i)
	{
		PassiveCards[i]->SetRenderOpacity(1.0f);
		PassiveCards[i]->SetImage(Managers->Widget->GetPassiveImages()[i]);
		PassiveCards[i]->SetLevel(Managers->Game->Player->GetAttackComponent()->GetPassiveTypes()[i]->GetLevel());
	}


	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			auto temp = CreateWidget<UPauseCard>(GetOwningPlayer(), CardClass);
			auto slot = Weapon_Grid->AddChildToGrid(temp);
			slot->SetColumn(j);
			slot->SetRow(i);
			WeaponCards.Add(temp);
			temp->SetRenderOpacity(0.0f);

			if (i == 0 && j == 0)
				slot->SetPadding(FMargin(FVector4f(0.0f, 0.0f, 30.0f, 14.0f)));

			else if (i == 0 && j == 1)
				slot->SetPadding(FMargin(FVector4f(15.0f, 0.0f, 15.0f, 14.0f)));

			else if (i == 0 && j == 2)
				slot->SetPadding(FMargin(FVector4f(30.0f, 0.0f, 15.0f, 14.0f)));

			else if (i == 1 && j == 0)
				slot->SetPadding(FMargin(FVector4f(0.0f, 14.0f, 30.0f, 0.0f)));

			else if (i == 1 && j == 1)
				slot->SetPadding(FMargin(FVector4f(15.0f, 14.0f, 15.0f, 0.0f)));

			else if (i == 1 && j == 2)
				slot->SetPadding(FMargin(FVector4f(30.0f, 14.0f, 0.0f, 0.0f)));
		}
	}

	for (int i = 0; i < Managers->Game->Player->GetAttackComponent()->GetAttackTypes().Num(); ++i)
	{
		WeaponCards[i]->SetRenderOpacity(1.0f);
		WeaponCards[i]->SetImage(Managers->Widget->GetWeaponImages()[i]);
		WeaponCards[i]->SetLevel(Managers->Game->Player->GetAttackComponent()->GetAttackTypes()[i]->GetLevel());
	}
}

void UPause::NativeTick(const FGeometry& geo, float dt)
{
	Super::NativeTick(geo, dt);

}

void UPause::Resume()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	Managers->Widget->RemovePopupWidget();
}

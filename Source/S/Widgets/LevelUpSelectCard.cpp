// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/LevelUpSelectCard.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "System/GMB.h"
#include "Components/AttackComponent.h"
#include "Components/CanvasPanel.h"
#include "System/PC.h"
#include "GameFramework/CharacterMovementComponent.h"

ULevelUpSelectCard::ULevelUpSelectCard(const FObjectInitializer& Init)
	:Super(Init)
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv0(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUP_Skill_LV0.LevelUP_Skill_LV0'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv1(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUP_Skill_LV1.LevelUP_Skill_LV1'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv2(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUP_Skill_LV2.LevelUP_Skill_LV2'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv3(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUP_Skill_LV3.LevelUP_Skill_LV3'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv4(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUP_Skill_LV4.LevelUP_Skill_LV4'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> ult(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUp_Skill_Ult.LevelUp_Skill_Ult'"));

	Lv0 = lv0.Object;
	Lv1 = lv1.Object;
	Lv2 = lv2.Object;
	Lv3 = lv3.Object;
	Lv4 = lv4.Object;
	Ult = ult.Object;
}

void ULevelUpSelectCard::NativeConstruct()
{
	Super::NativeConstruct();
	User = Managers->Game->Player;
	
	for (const auto& temp : User->GetAttackComponent()->GetAttackTypes())
	{
		if (temp->GetAttackType() == CardType)
		{
			Level = temp->GetLevel();
			Attack = temp;
		}
	}


	switch (Level)
	{
	case 0:
	{
		Level_Star->SetBrushFromTexture(Lv0);
		break;
	}

	case 1:
	{
		Level_Star->SetBrushFromTexture(Lv1);
		break;
	}

	case 2:
	{
		Level_Star->SetBrushFromTexture(Lv2);
		break;
	}

	case 3:
	{
		Level_Star->SetBrushFromTexture(Lv3);
		break;
	}

	case 4:
	{
		Level_Star->SetBrushFromTexture(Lv4);
		break;
	}
	}


	
}

FReply ULevelUpSelectCard::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	++Attack->GetLevel();
	Managers->Widget->RemovePopupWidget();
	return Reply;
}

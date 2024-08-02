// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/PauseCard.h"
#include "Components/Image.h"

UPauseCard::UPauseCard(const FObjectInitializer& Init)
	:Super(Init)
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv0(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Pause_UI_Tex/Card_LV1.Card_LV1'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv1(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Pause_UI_Tex/Card_LV2.Card_LV2'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv2(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Pause_UI_Tex/Card_LV3.Card_LV3'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv3(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Pause_UI_Tex/Card_LV4.Card_LV4'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv4(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Pause_UI_Tex/Card_LV5.Card_LV5'"));

	Lv0 = lv0.Object;
	Lv1 = lv1.Object;
	Lv2 = lv2.Object;
	Lv3 = lv3.Object;
	Lv4 = lv4.Object;
}

void UPauseCard::SetImage(UTexture2D* texture)
{
	Item_Image->SetBrushFromSoftTexture(texture);
}

void UPauseCard::SetLevel(const int32& lv)
{
	switch (lv)
	{
	case 0:
	{
		Skill_Slot_Card->SetBrushFromSoftTexture(Lv0);
		break;
	}

	case 1:
	{
		Skill_Slot_Card->SetBrushFromSoftTexture(Lv0);
		break;
	}
	case 2:
	{
		Skill_Slot_Card->SetBrushFromSoftTexture(Lv1);
		break;
	}
	case 3:
	{
		Skill_Slot_Card->SetBrushFromSoftTexture(Lv2);
		break;
	}

	case 4:
	{
		Skill_Slot_Card->SetBrushFromSoftTexture(Lv3);
		break;
	}

	case 5:
	{
		Skill_Slot_Card->SetBrushFromSoftTexture(Lv4);
		break;
	}
	}
}

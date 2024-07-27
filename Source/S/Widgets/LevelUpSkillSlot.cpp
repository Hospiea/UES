// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/LevelUpSkillSlot.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "System/GMB.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "Components/HorizontalBoxSlot.h"
#include "Slots.h"

ULevelUpSkillSlot::ULevelUpSkillSlot(const FObjectInitializer& Init)
	:Super(Init)
{
	static ConstructorHelpers::FClassFinder<USlots> slotclass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Art/UI/UI_LevelUp/BP_Slots.BP_Slots_C'"));

	SlotClass = slotclass.Class;
}



void ULevelUpSkillSlot::NativeConstruct()
{
	Super::NativeConstruct();

	for (int i = 0; i < 6; ++i)
	{
		auto weapon = CreateWidget<USlots>(GetWorld(), SlotClass);
		auto temp1 = Weapon_Frame_Box->AddChildToHorizontalBox(weapon);
		temp1->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
		WeaponImages.Add(weapon);

		
		auto passive = CreateWidget<USlots>(GetWorld(), SlotClass);
		auto temp2 = Passive_Frame_Box->AddChildToHorizontalBox(passive);
		temp2->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
		PassiveImages.Add(passive);
	}

	for (int i = 0; i < Managers->Widget->GetWeaponImages().Num(); ++i)
	{
		WeaponImages[i]->SetImage(Managers->Widget->GetWeaponImages()[i]);
	}

	for (int i = 0; i < Managers->Widget->GetPassiveImages().Num(); ++i)
	{
		PassiveImages[i]->SetImage(Managers->Widget->GetPassiveImages()[i]);
	}
}

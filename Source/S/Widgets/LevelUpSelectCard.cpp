// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/LevelUpSelectCard.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "System/GMB.h"
#include "Components/AttackComponent.h"
#include "Components/CanvasPanel.h"
#include "System/PC.h"
#include "Data/TextureAsset.h"
#include "Attacks/Basic/Sheild.h"
#include "Attacks/Basic/Sword.h"
#include "Attacks/Basic/Staff.h"
#include "Attacks/Basic/Axe.h"
#include "Attacks/Basic/Spear.h"
#include "LevelUpSkillSlot.h"
#include "GameFramework/CharacterMovementComponent.h"

ULevelUpSelectCard::ULevelUpSelectCard(const FObjectInitializer& Init)
	:
	Super(Init),
	IsFirst(false),
	IsPassive(false),
	RandIndex(-1),
	IsAlreadyHave(false),
	WeaponType(UBasic::AttackType::Sword),
	PassiveType(UBasic::PassiveType::Fire)
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv0(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUP_Skill_LV0.LevelUP_Skill_LV0'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv1(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUP_Skill_LV1.LevelUP_Skill_LV1'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv2(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUP_Skill_LV2.LevelUP_Skill_LV2'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv3(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUP_Skill_LV3.LevelUP_Skill_LV3'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> lv4(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUP_Skill_LV4.LevelUP_Skill_LV4'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> ult(TEXT("/Script/Engine.Texture2D'/Game/Art/UI/UI_Texs/Levelup_PopUp_Tex/LevelUp_Skill_Ult.LevelUp_Skill_Ult'"));
	static ConstructorHelpers::FObjectFinder <UTextureAsset> texture(TEXT("/Script/S.TextureAsset'/Game/Assets/Data/Textures.Textures'"));

	Textures = texture.Object;
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
	Level = -1;
	IsFirst = false;
	IsAlreadyHave = false;
	User = Managers->Game->Player;

	RandIndex = FMath::Rand() % 5;
	//IsPassive = FMath::RandBool();

	WeaponType = static_cast<UBasic::AttackType>(RandIndex);
	PassiveType = static_cast<UBasic::PassiveType>(RandIndex);

	if (!IsPassive)
	{
		for (const auto& temp : User->GetAttackComponent()->GetAttackTypes())
		{
			if (temp->GetAttackType() == WeaponType)
			{
				Level = temp->GetLevel();
				Item_Image->SetBrushFromSoftTexture(Textures->MainWeapons[static_cast<int32>(WeaponType)]);
				Attack = temp;
			}
		}
	}
	else
	{
		for (const auto& temp : User->GetAttackComponent()->GetPassiveTypes())
		{
			if (temp->GetPassiveType() == PassiveType)
			{
				Level = temp->GetLevel();
				Item_Image->SetBrushFromSoftTexture(Textures->Passives[static_cast<int32>(PassiveType)]);
				Attack = temp;
			}
		}
	}

	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Cyan, FString::Printf(TEXT("%d"), Level));


	if (Level == -1)
	{
		Level = 0;
		IsFirst = true;
		if (!IsPassive)
		{
			Item_Image->SetBrushFromSoftTexture(Textures->MainWeapons[RandIndex]);
			WeaponType = static_cast<UBasic::AttackType>(RandIndex);
		}

		else
		{
			Item_Image->SetBrushFromSoftTexture(Textures->Passives[RandIndex]);
			PassiveType = static_cast<UBasic::PassiveType>(RandIndex);
		}
	}




	for (const auto& temp : User->GetAttackComponent()->GetAttackTypes())
	{
		if (temp->GetAttackType() == WeaponType)
		{
			Level = temp->GetLevel();
			Item_Image->SetBrushFromSoftTexture(Textures->MainWeapons[static_cast<int32>(WeaponType)]);
			Attack = temp;
			IsAlreadyHave = true;
		}

		else if (temp->GetPassiveType() == PassiveType)
		{

		}
	}









#pragma region Hide
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
#pragma endregion


}

FReply ULevelUpSelectCard::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	/*++Attack->GetLevel();
	Managers->Widget->RemovePopupWidget();*/
	if (IsFirst)
	{
		if (IsPassive)
		{
			PassiveFactory(PassiveType);
			Managers->Widget->GetPassiveImages().Add(Textures->Passives[RandIndex]);
		}

		else
		{
			WeaponFactory(WeaponType);
			Managers->Widget->GetWeaponImages().Add(Textures->MainWeapons[RandIndex]);
		}
			
	}

	else
		++Attack->GetLevel();


		

	Managers->Widget->RemovePopupWidget();
	return Reply;
}

void ULevelUpSelectCard::WeaponFactory(const UBasic::AttackType& attack)
{
	switch (attack)
	{
	case UBasic::AttackType::Sword:
	{
		auto temp = NewObject<USword>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Axe:
	{
		auto temp = NewObject<UAxe>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Hammer:
	{
		/*auto temp = NewObject<UHammer>(User);
		temp->SetAttackType(attack);
		User->GetAttackComponent()->AddAttack(temp);*/
		break;
	}

	case UBasic::AttackType::Spear:
	{
		auto temp = NewObject<USpear>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Staff:
	{
		auto temp = NewObject<UStaff>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}
	}
}

void ULevelUpSelectCard::PassiveFactory(const UBasic::PassiveType& passive)
{

}
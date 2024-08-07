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
#include "Attacks/Basic/Passive/Fire.h"
#include "Attacks/Basic/Passive/Life.h"
#include "Attacks/Basic/Passive/Magnetic.h"
#include "Attacks/Basic/Passive/Will.h"
#include "Attacks/Basic/Passive/Wind.h"
#include "Attacks/Basic/Hammer.h"
#include "Attacks/Basic/Shoes.h"
#include "Attacks/Basic/Chakram.h"
#include "Attacks/Basic/Negative.h"
#include "Attacks/Basic/Dagger.h"
#include "Attacks/Basic/Positive.h"
#include "Attacks/Basic/FireBottle.h"
#include "Attacks/Basic/Rifle.h"
#include "LevelUpSkillSlot.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"

bool ULevelUpSelectCard::bIsWeaponMax = false;
bool ULevelUpSelectCard::bIsPassiveMax = false;
TArray<int32> ULevelUpSelectCard::WeaponIndexes;
TArray<int32> ULevelUpSelectCard::PassiveIndexes;
TArray<FText> ULevelUpSelectCard::AttackNames;
TArray<FText> ULevelUpSelectCard::PassiveNames;

ULevelUpSelectCard::ULevelUpSelectCard(const FObjectInitializer& Init)
	:
	Super(Init),
	Level(-1),
	WeaponType(UBasic::AttackType::Sword),
	PassiveType(UBasic::PassiveType::Fire),
	IsFirst(false),
	IsPassive(false),
	RandIndex(-1)
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

void ULevelUpSelectCard::ReRoll()
{
	GetRandomCard();
}

void ULevelUpSelectCard::NativeConstruct()
{
	Super::NativeConstruct();
	User = Managers->Game->Player;

	if (AttackNames.Num() == 0)
	{
		AttackNames.Push(FText::FromString(TEXT("Sword")));
		AttackNames.Push(FText::FromString(TEXT("Axe")));
		AttackNames.Push(FText::FromString(TEXT("Hammer")));
		AttackNames.Push(FText::FromString(TEXT("Spear")));
		AttackNames.Push(FText::FromString(TEXT("Staff")));
		AttackNames.Push(FText::FromString(TEXT("Dagger")));
		AttackNames.Push(FText::FromString(TEXT("Shield")));
		AttackNames.Push(FText::FromString(TEXT("FireBottle")));
		AttackNames.Push(FText::FromString(TEXT("Rifle")));
		AttackNames.Push(FText::FromString(TEXT("Chakram")));
		AttackNames.Push(FText::FromString(TEXT("Shoes")));
		AttackNames.Push(FText::FromString(TEXT("Negative")));
		AttackNames.Push(FText::FromString(TEXT("Positive")));


		PassiveNames.Push(FText::FromString(TEXT("Fire")));
		PassiveNames.Push(FText::FromString(TEXT("Wind")));
		PassiveNames.Push(FText::FromString(TEXT("Will")));
		PassiveNames.Push(FText::FromString(TEXT("Magnetic")));
		PassiveNames.Push(FText::FromString(TEXT("Life")));
		PassiveNames.Push(FText::FromString(TEXT("Iron")));
		PassiveNames.Push(FText::FromString(TEXT("Time")));
		PassiveNames.Push(FText::FromString(TEXT("Circular")));
		PassiveNames.Push(FText::FromString(TEXT("Thunder")));
		PassiveNames.Push(FText::FromString(TEXT("Rock")));
		PassiveNames.Push(FText::FromString(TEXT("Belief")));
		PassiveNames.Push(FText::FromString(TEXT("Experience")));
		PassiveNames.Push(FText::FromString(TEXT("Rich")));
	}

	GetRandomCard();
}

FReply ULevelUpSelectCard::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	UGameplayStatics::SetGamePaused(GetWorld(), false);

	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Cyan, FString::Printf(TEXT("%d"), IsFirst));

	if (IsFirst)
	{
		if (IsPassive)
		{
			PassiveFactory(PassiveType);
			Managers->Widget->GetPassiveImages().Push(Textures->Passives[static_cast<int32>(PassiveType)]);
			PassiveIndexes.Push(static_cast<int32>(PassiveType));
			if (PassiveIndexes.Num() == 6)
				bIsPassiveMax = true;
		}

		else if(!IsPassive)
		{
			WeaponFactory(WeaponType);
			Managers->Widget->GetWeaponImages().Push(Textures->MainWeapons[static_cast<int32>(WeaponType)]);
			WeaponIndexes.Push(static_cast<int32>(WeaponType));
			if (WeaponIndexes.Num() == 6)
				bIsWeaponMax = true;
		}
	}

	else if(!IsFirst)
	{
		Attack->LevelUp();
	}

	
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
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;

	}
	case UBasic::AttackType::Axe:
	{
		auto temp = NewObject<UAxe>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Hammer:
	{
		auto temp = NewObject<UHammer>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Spear:
	{
		auto temp = NewObject<USpear>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Staff:
	{
		auto temp = NewObject<UStaff>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Dagger:
	{
		auto temp = NewObject<UDagger>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Shield:
	{
		auto temp = NewObject<USheild>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::FireBottle:
	{
		auto temp = NewObject<UFireBottle>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Rifle:
	{
		auto temp = NewObject<URifle>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Chakram:
	{
		auto temp = NewObject<UChakram>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Shoes:
	{
		auto temp = NewObject<UShoes>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Negative:
	{
		auto temp = NewObject<UNegative>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::AttackType::Positive:
	{
		auto temp = NewObject<UPositive>(User);
		temp->SetAttackType(attack);
		temp->SetPassive(false);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}
	}
}

void ULevelUpSelectCard::PassiveFactory(const UBasic::PassiveType& passive)
{
	switch (passive)
	{
	case UBasic::PassiveType::Fire:
	{
		auto temp = NewObject<UFire>(User);
		temp->SetPassiveType(passive);
		temp->SetPassive(true);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::PassiveType::Wind:
	{
		auto temp = NewObject<UWind>(User);
		temp->SetPassiveType(passive);
		temp->SetPassive(true);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::PassiveType::Will:
	{
		/*auto temp = NewObject<UHammer>(User);
		temp->SetAttackType(attack);
		User->GetAttackComponent()->AddAttack(temp);*/
		break;
	}

	case UBasic::PassiveType::Magnetic:
	{
		auto temp = NewObject<UMagnetic>(User);
		temp->SetPassiveType(passive);
		temp->SetPassive(true);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}

	case UBasic::PassiveType::Life:
	{
		auto temp = NewObject<ULife>(User);
		temp->SetPassiveType(passive);
		temp->SetPassive(true);
		temp->GetLevel() = 0;
		User->GetAttackComponent()->AddAttack(temp);
		break;
	}
	}
}

void ULevelUpSelectCard::RandSelectCard()
{
	if (!IsPassive)
	{
		for (const auto& temp : User->GetAttackComponent()->GetAttackTypes())
		{
			if (temp->GetAttackType() == WeaponType)
			{
				Level = temp->GetLevel();
				Item_Image->SetBrushFromSoftTexture(Textures->MainWeapons[static_cast<int32>(WeaponType)]);
				Attack = temp;
				Skill_Name->SetText(AttackNames[static_cast<int32>(WeaponType)]);
			}
		}
	}
	else if (IsPassive)
	{
		for (const auto& temp : User->GetAttackComponent()->GetPassiveTypes())
		{
			if (temp->GetPassiveType() == PassiveType)
			{
				Level = temp->GetLevel();
				Item_Image->SetBrushFromSoftTexture(Textures->Passives[static_cast<int32>(PassiveType)]);
				Attack = temp;
				Skill_Name->SetText(PassiveNames[static_cast<int32>(PassiveType)]);
			}
		}
	}
}

void ULevelUpSelectCard::GetRandomCard()
{
	
	if (bIsWeaponMax && !IsPassive)
	{
		RandIndex = FMath::Rand() % 6;
		WeaponType = static_cast<UBasic::AttackType>(WeaponIndexes[RandIndex]);
		for (const auto& temp : User->GetAttackComponent()->GetAttackTypes())
		{
			if (temp->GetAttackType() == WeaponType)
			{
				Level = temp->GetLevel();
				Item_Image->SetBrushFromSoftTexture(Textures->MainWeapons[static_cast<int32>(WeaponType)]);
				Attack = temp;
				Skill_Name->SetText(AttackNames[static_cast<int32>(WeaponType)]);
				SetStars();
				return;
			}
		}
	}

	else if (bIsPassiveMax && IsPassive)
	{
		RandIndex = FMath::Rand() % 6;
		PassiveType = static_cast<UBasic::PassiveType>(PassiveIndexes[RandIndex]);
		for (const auto& temp : User->GetAttackComponent()->GetPassiveTypes())
		{
			if (temp->GetPassiveType() == PassiveType)
			{
				Level = temp->GetLevel();
				Item_Image->SetBrushFromSoftTexture(Textures->Passives[static_cast<int32>(PassiveType)]);
				Attack = temp;
				Skill_Name->SetText(PassiveNames[static_cast<int32>(PassiveType)]);
				SetStars();
				return;
			}
		}
	}







	Level = -1;
	IsFirst = false;
	RandIndex = FMath::Rand() % 13;
	//IsPassive = FMath::RandBool();
	IsPassive = false;
	WeaponType = static_cast<UBasic::AttackType>(RandIndex);
	PassiveType = static_cast<UBasic::PassiveType>(RandIndex);


	while (true)
	{
		RandSelectCard();
		if (Level != 5)
			break;
	}




	if (Level == -1)
	{
		Level = 0;
		IsFirst = true;
		if (!IsPassive)
		{
			Item_Image->SetBrushFromSoftTexture(Textures->MainWeapons[static_cast<int32>(WeaponType)]);
			Skill_Name->SetText(AttackNames[static_cast<int32>(WeaponType)]);
		}

		else if (IsPassive)
		{
			Item_Image->SetBrushFromSoftTexture(Textures->Passives[static_cast<int32>(PassiveType)]);
			Skill_Name->SetText(PassiveNames[static_cast<int32>(PassiveType)]);
		}
	}





	if (bIsWeaponMax && !IsPassive)
	{
		RandIndex = FMath::Rand() % 6;
		WeaponType = static_cast<UBasic::AttackType>(WeaponIndexes[RandIndex]);
		Skill_Name->SetText(AttackNames[RandIndex]);

	}

	else if (bIsPassiveMax && IsPassive)
	{
		RandIndex = FMath::Rand() % 6;
		PassiveType = static_cast<UBasic::PassiveType>(PassiveIndexes[RandIndex]);
		Skill_Name->SetText(PassiveNames[RandIndex]);
	}




	SetStars();

}

void ULevelUpSelectCard::SetStars()
{
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

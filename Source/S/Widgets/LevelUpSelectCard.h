// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WidgetBase.h"
#include "Attacks/Basic/Basic.h"
#include "LevelUpSelectCard.generated.h"

class UImage;
class UTexture2D;
class AUser;
class UCanvasPanel;
class UTextureAsset;
class UTextBlock;

UCLASS()
class S_API ULevelUpSelectCard : public UWidgetBase
{
	GENERATED_BODY()
	
public:
	ULevelUpSelectCard(const FObjectInitializer& Init);
	bool IsSame(const ULevelUpSelectCard& other)
	{
		return (IsPassive == other.IsPassive && RandIndex == other.RandIndex);
	}
	void ReRoll();

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Level_Star;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCanvasPanel> Skill_Card;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Item_Image;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Skill_Name;

	static TArray<FText> AttackNames;
	static TArray<FText> PassiveNames;	
	
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
	UPROPERTY()
	TObjectPtr<UTexture2D> Lv0;

	UPROPERTY()
	TObjectPtr<UTexture2D> Lv1;

	UPROPERTY()
	TObjectPtr<UTexture2D> Lv2;

	UPROPERTY()
	TObjectPtr<UTexture2D> Lv3;

	UPROPERTY()
	TObjectPtr<UTexture2D> Lv4;

	UPROPERTY()
	TObjectPtr<UTexture2D> Ult;

	UPROPERTY()
	TObjectPtr<AUser> User;

	UPROPERTY()
	TObjectPtr<UBasic> Attack;

	UPROPERTY()
	TObjectPtr<UTextureAsset> Textures;

	UPROPERTY()
	int32 Level;

	UBasic::AttackType WeaponType;
	UBasic::PassiveType PassiveType;

	bool IsFirst;
	bool IsPassive;
	int32 RandIndex;

	static bool bIsWeaponMax;
	static bool bIsPassiveMax;
	static TArray<int32> WeaponIndexes;
	static TArray<int32> PassiveIndexes;

private:
	void WeaponFactory(const UBasic::AttackType& attack);
	void PassiveFactory(const UBasic::PassiveType& passive);
	friend class UAttackComponent;
	void RandSelectCard();
	void GetRandomCard();
	void SetStars();
};

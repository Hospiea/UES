// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Battle.generated.h"

class UTextBlock;
class UButton;
class UProgressBar;
class AUser;
class UJoy;
class UCanvasPanel;

UCLASS()
class S_API UBattle : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UBattle(const FObjectInitializer& Init);
	inline void SetPlayer(AUser* user) { User = user; }

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& geo, float dt) override;


	virtual FReply NativeOnTouchStarted(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent) override;
	virtual FReply NativeOnTouchMoved(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent) override;
	virtual FReply NativeOnTouchEnded(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent) override;



protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCanvasPanel> Canvas;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> Timer;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Money_Text;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> KillCount_Text;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> EXP_Gauge;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> Pause_Game;

	UPROPERTY()
	TObjectPtr<AUser> User;

	UPROPERTY()
	TSubclassOf<UJoy> JoyClass;

	UPROPERTY()
	TObjectPtr<UJoy> Joy;

	UPROPERTY()
	FVector2D TouchStartLocation;

	UFUNCTION()
	void PauseButton();
};

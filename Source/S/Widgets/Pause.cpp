// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Pause.h"
#include "Components/Button.h"
#include "PauseCard.h"
#include "System/GMB.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/CanvasPanel.h"

UPause::UPause(const FObjectInitializer& Init)
	:Super(Init)
{
	static ConstructorHelpers::FClassFinder<UPauseCard> pauseclass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Art/UI/UI_Pause/BP_Pause_Skill_Slot.BP_Pause_Skill_Slot_C'"));
	CardClass = pauseclass.Class;
}

void UPause::NativeConstruct()
{
	Button_Continue->OnClicked.AddDynamic(this, &UPause::Resume);

	for (int i = 0; i < Managers->Widget->GetPassiveImages().Num(); ++i)
	{

	}

}

void UPause::NativeTick(const FGeometry& geo, float dt)
{
	Super::NativeTick(geo, dt);

}

void UPause::Resume()
{
	Managers->Widget->RemovePopupWidget();
}

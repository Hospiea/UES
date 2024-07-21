// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Pause.h"
#include "Components/Button.h"
#include "System/GMB.h"

void UPause::NativeConstruct()
{
	Button_Continue->OnClicked.AddDynamic(this, &UPause::Resume);
}

void UPause::NativeTick(const FGeometry& geo, float dt)
{
	Super::NativeTick(geo, dt);

}

void UPause::Resume()
{
	Managers->Widget->RemovePopupWidget();
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Slots.h"
#include "Components/Image.h"

void USlots::SetImage(const UTexture2D* image)
{
	Image->SetBrushFromSoftTexture(image);
	Image->SetColorAndOpacity(FLinearColor::White);
}

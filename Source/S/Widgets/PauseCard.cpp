// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/PauseCard.h"
#include "Components/Image.h"

void UPauseCard::SetImage(UTexture2D* texture)
{
	Item_Image->SetBrushFromSoftTexture(texture);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/GameObjects.h"
#include "Components/CapsuleComponent.h"

AGameObjects::AGameObjects()
{
	GetCapsuleComponent()->SetCapsuleRadius(10.0f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(10.0f);

	static ConstructorHelpers::FObjectFinder<UFlipbookAsset> flipbooks(TEXT("/Script/S.FlipbookAsset'/Game/Assets/Data/Flipbooks.Flipbooks'"));
	Flipbooks = flipbooks.Object;

}
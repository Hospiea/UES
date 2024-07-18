// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Center.h"

// Sets default values for this component's properties
UCenter::UCenter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	CurrentRotation = FRotator::ZeroRotator;

	// ...
}


// Called when the game starts
void UCenter::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCenter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentRotation.Pitch += -20.0f * DeltaTime;

	// 누적된 회전을 설정
	SetRelativeRotation(CurrentRotation);
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DetectComponent.h"
#include "GameObject/Player/User.h"
#include "Components/BoxComponent.h"

// Sets default values for this component's properties
UDetectComponent::UDetectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	DetectRange = CreateDefaultSubobject<UBoxComponent>(TEXT("Detection"));
	DetectRange->SetupAttachment(this);
	DetectRange->SetCollisionProfileName(TEXT("Detection"));

	ObtainRange = CreateDefaultSubobject<UBoxComponent>(TEXT("Obtain"));
	ObtainRange->SetupAttachment(this);
	ObtainRange->SetCollisionProfileName(TEXT("Obtain"));
}


// Called when the game starts
void UDetectComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


// Called every frame
void UDetectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


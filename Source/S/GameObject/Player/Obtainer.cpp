// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/Player/Obtainer.h"
#include "Components/BoxComponent.h"
#include "System/GMB.h"
#include "GameObject/Item/ExpOrb.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AObtainer::AObtainer()
	:Range(20.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObtainRange = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = ObtainRange;
	ObtainRange->SetCollisionProfileName(TEXT("Obtain"));
	ObtainRange->SetBoxExtent(FVector(Range, Range, Range));
	ObtainRange->SetGenerateOverlapEvents(true);

}

// Called when the game starts or when spawned
void AObtainer::BeginPlay()
{
	Super::BeginPlay();
	ObtainRange->OnComponentBeginOverlap.AddDynamic(this, &AObtainer::OnDetecting);
	User = Managers->Game->Player;
	AttachToActor(User, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void AObtainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObtainer::OnDetecting(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AExpOrb* orb = Cast<AExpOrb>(OtherActor))
	{
		orb->Grabbed();
	}
}


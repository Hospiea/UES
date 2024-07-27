// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DetectComponent.h"
#include "GameObject/Player/User.h"
#include "Components/BoxComponent.h"
#include "GameObject/Enemy.h"

// Sets default values for this component's properties
UDetectComponent::UDetectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UDetectComponent::BeginPlay()
{
	Super::BeginPlay();
	DetectRange = NewObject<UBoxComponent>(this);
	DetectRange->SetupAttachment(GetOwner()->GetRootComponent());
	DetectRange->RegisterComponent();
	DetectRange->SetCollisionProfileName(TEXT("Detection"));

	ObtainRange = NewObject<UBoxComponent>(this);
	ObtainRange->SetupAttachment(GetOwner()->GetRootComponent());
	ObtainRange->RegisterComponent();
	ObtainRange->SetCollisionProfileName(TEXT("Obtain"));

	DetectRange->SetBoxExtent(FVector(300.0f, 300.0f, 300.0f));
	//DetectRange->bHiddenInGame = false;

	DetectRange->OnComponentBeginOverlap.AddDynamic(this, &UDetectComponent::OnDetecting);
	DetectRange->OnComponentEndOverlap.AddDynamic(this, &UDetectComponent::EndDetecting);
	EnemyNumbers = 0;
}


// Called every frame
void UDetectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	

}

const TObjectPtr<AEnemy> UDetectComponent::GetClosetEnemy()
{
	if (Enemylist.Num() == 0) return nullptr;

	AEnemy* Target = nullptr;

	FVector MyLocation = GetOwner()->GetActorLocation();
	float Min = FLT_MAX;

	for (AEnemy* enemy : Enemylist)
	{
		FVector TargetLocation = enemy->GetActorLocation();
		float Distance = FVector::Dist(MyLocation, TargetLocation);
		if (Distance < Min)
		{
			Min = Distance;
			Target = enemy;
		}
	}
	return Target;
}

void UDetectComponent::OnDetecting(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Enemylist.Add(Cast<AEnemy>(OtherActor));
	++EnemyNumbers;
}

void UDetectComponent::EndDetecting(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Enemylist.Remove(Cast<AEnemy>(OtherActor));
	--EnemyNumbers;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/MainCamera.h"
#include "Camera.h"
#include "GameObject/Player/User.h"

// Sets default values
AMainCamera::AMainCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraComponent = CreateDefaultSubobject<UCamera>(TEXT("CameraComponent"));
	RootComponent = CameraComponent;
	CameraComponent->SetProjectionMode(ECameraProjectionMode::Orthographic);
	CameraComponent->SetOrthoWidth(500.0f);

}

// Called when the game starts or when spawned
void AMainCamera::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocationAndRotation(FVector(0.0f, 50.0f, 0.0f), FRotator(0.0f, -90.0f, 0.0f));
	CameraComponent->bConstrainAspectRatio = true;
	CameraComponent->AspectRatio = 0.6f;
}

// Called every frame
void AMainCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Location = User->GetActorLocation();

	SetActorLocation(FVector(Location.X, 50.0f, Location.Z));
}


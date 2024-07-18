// Fill out your copyright notice in the Description page of Project Settings.


#include "System/PC.h"
#include "Camera/MainCamera.h"
#include "GameObject/Player/User.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Attacks/Basic/Basic.h"


APC::APC(const FObjectInitializer& Init)
	:Super(Init)
{
	
}

void APC::BeginPlay()
{
	Super::BeginPlay();
#pragma region Hide
	auto temp = GetWorld()->SpawnActor<AMainCamera>(FVector(0.0f, 50.0f, 0.0f), FRotator(0.0f, -90.0f, 0.0f));
	SetViewTarget(temp);
	temp->SetPlayer(Cast<AUser>(GetPawn()));
#pragma endregion
	User = Cast<AUser>(GetPawn());


	Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	Subsystem->AddMappingContext(Context, 0);

	UEnhancedInputComponent* Component = Cast<UEnhancedInputComponent>(InputComponent);

	Component->BindAction(Move, ETriggerEvent::Triggered, this, &APC::MoveFunc);
	Component->BindAction(Move, ETriggerEvent::Completed, this, &APC::StopFunc);
	Component->BindAction(Left, ETriggerEvent::Triggered, this, &APC::LeftFunc);
}

void APC::MoveFunc(const FInputActionValue& value)
{
	FVector2D Dir = value.Get<FVector2D>();

	Dir.Normalize();
	Dir *= 150.0f;

	User->GetCharacterMovement()->Velocity = FVector(Dir.X, 0.0f, Dir.Y);
}

void APC::StopFunc(const FInputActionValue& value)
{
	FVector2D Dir = value.Get<FVector2D>();

	FVector Vel = User->GetCharacterMovement()->Velocity;

	if (Dir.X == 0.0f)
	{
		User->GetCharacterMovement()->Velocity = FVector(0.0f, 0.0f, 0.0f);
	}

	if (Dir.Y == 0.0f)
	{
		User->GetCharacterMovement()->Velocity = FVector(0.0f, 0.0f, 0.0f);
	}
}

void APC::LeftFunc(const FInputActionValue& value)
{
	User->GetBasicAttack()->BasicAttack();
}
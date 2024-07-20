// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC.generated.h"

class AMainCamera;
class UInputAction;
class UInputMappingContext;
class UEnhancedInputLocalPlayerSubsystem;
struct FInputActionValue;
class AUser;

UCLASS()
class S_API APC : public APlayerController
{
	GENERATED_BODY()
	
public:
	APC(const FObjectInitializer& Init);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AUser> User;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<AMainCamera> MainCamera;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> Subsystem;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> Move;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> Left;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> Context;

	UPROPERTY(VisibleAnywhere)
	float Timer;

	void MoveFunc(const FInputActionValue& value);
	void StopFunc(const FInputActionValue& value);
	void LeftFunc(const FInputActionValue& value);
};

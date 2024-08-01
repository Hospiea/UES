// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obtainer.generated.h"

class UBoxComponent;
class AUser;

UCLASS()
class S_API AObtainer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObtainer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere)
	float Range;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> ObtainRange;

	UFUNCTION()
	void OnDetecting(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY()
	TObjectPtr<AUser> User;

};

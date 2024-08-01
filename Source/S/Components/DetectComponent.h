// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DetectComponent.generated.h"

class AUser;
class UBoxComponent;
class AEnemy;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S_API UDetectComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDetectComponent();
	inline void SetPlayer(AUser* user) { User = user; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	const TObjectPtr<AEnemy> GetClosetEnemy();
	inline const int32& GetDetectedEnemyNumber() { return EnemyNumbers; }

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AUser> User;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> DetectRange;

	

	UPROPERTY()
	TArray<TObjectPtr<AEnemy>> Enemylist;

	UFUNCTION()
	void OnDetecting(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void EndDetecting(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	int32 EnemyNumbers;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/RangeBase.h"
#include "PChakram.generated.h"

class UChakram;
class APChakramBody;
class USceneComponent;

UCLASS()
class S_API APChakram : public ARangeBase
{
	GENERATED_BODY()
	
public:
	APChakram();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APChakramBody> Body1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APChakramBody> Body2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<APChakramBody> ChakramBodyClass;


private:
	friend class UChakram;
	static UChakram* Basic;


	
};

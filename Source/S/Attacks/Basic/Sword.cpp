// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/Basic/Sword.h"
#include "GameObject/Projectiles/PSword.h"
#include "GameObject/Player/User.h"
#include "Components/Center.h"
#include "Kismet/KismetMathLibrary.h"

USword::USword()
{
	static ConstructorHelpers::FClassFinder<APSword> sword(TEXT("/Script/Engine.Blueprint'/Game/Assets/Blueprints/GameObjects/Projectiles/Basic/BP_PSword.BP_PSword_C'"));
	SwordClass = sword.Class;
}

void USword::BasicAttack(const FVector2D& Dir)
{
	Super::BasicAttack(Dir);

    FVector2D NewDir = Dir * 30.0f;
    FVector SpawnLocation = User->GetActorLocation() + FVector(NewDir.X, 0.0f, NewDir.Y);

    APSword* temp = World->SpawnActor<APSword>(SwordClass, SpawnLocation, FRotator::ZeroRotator);
    if (temp)
    {
        FVector TargetLocation = SpawnLocation + FVector(NewDir.X, 0.0f, NewDir.Y);
        FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(FVector(1.0f, 0.0f, 0.0f), SpawnLocation);

        FRotator AdjustedRotation = FRotator(Rotation.Yaw, 0.0f, 0.0f);

        temp->SetActorRotation(AdjustedRotation);
        temp->AttachToComponent(User->GetCenter(), FAttachmentTransformRules::KeepWorldTransform);
    }
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Battle.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "GameObject/Player/User.h"
#include "System/GMB.h"
#include "Components/Button.h"
#include "Widgets/Joy.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "System/PC.h"
#include "GameFramework/CharacterMovementComponent.h"

UBattle::UBattle(const FObjectInitializer& Init)
	:Super(Init)
{
	static ConstructorHelpers::FClassFinder<UJoy> joyclass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Assets/Blueprints/System/BP_Joy.BP_Joy_C'"));
	JoyClass = joyclass.Class;
}

void UBattle::NativeConstruct()
{
	Super::NativeConstruct();
	Timer->SetText(FText::FromString(FString::Printf(TEXT("00:00"))));
	EXP_Gauge->SetPercent(0.0f);

	Pause_Game->OnClicked.AddDynamic(this, &UBattle::PauseButton);
}

void UBattle::NativeTick(const FGeometry& geo, float dt)
{
	Super::Tick(geo, dt);
	if (!User)
		User = Managers->Game->Player;


	EXP_Gauge->SetPercent(User->GetExpPercent());
	Money_Text->SetText(FText::FromString(FString::Printf(TEXT("Lv.%d"), User->GetLevel())));
	KillCount_Text->SetText(FText::FromString(FString::Printf(TEXT("%d"), Managers->Game->KillCounts)));
}



FReply UBattle::NativeOnTouchStarted(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
	FReply Reply = Super::NativeOnTouchStarted(InGeometry, InGestureEvent);

	FVector2D TouchLocation = InGestureEvent.GetScreenSpacePosition();
	TouchStartLocation = InGeometry.AbsoluteToLocal(TouchLocation);


	Joy = CreateWidget<UJoy>(GetOwningPlayer(), JoyClass);
	auto slot = Canvas->AddChildToCanvas(Joy);
	slot->SetSize(FVector2D(100, 100));
	slot->SetPosition(TouchStartLocation);

	return Reply;
}

FReply UBattle::NativeOnTouchMoved(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
	FReply Reply = Super::NativeOnTouchStarted(InGeometry, InGestureEvent);
	FVector2D TouchLocation = InGestureEvent.GetScreenSpacePosition();
	FVector2D CurrentLocation = InGeometry.AbsoluteToLocal(TouchLocation);

	FVector2D Dir = CurrentLocation - TouchStartLocation;
	Dir.Normalize();
	Dir *= User->GetStats().Speed;

	User->GetCharacterMovement()->Velocity = FVector(Dir.X, 0.0f, -Dir.Y);
	Managers->Controller->SetDir(FVector2D(Dir.X, -Dir.Y));

	return Reply;
}

FReply UBattle::NativeOnTouchEnded(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
	FReply Reply = Super::NativeOnTouchStarted(InGeometry, InGestureEvent);

	User->GetCharacterMovement()->Velocity = FVector::ZeroVector;
	Joy->RemoveFromParent();

	return Reply;
}

void UBattle::PauseButton()
{
	Managers->Widget->Pause();
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/AuraCharacter.h"

/*
 * Step 1 - ensure replication for this class
 */
AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

/* BEGIN PLAY()
 * Step 2 - check if AuraContext exists (FATAL ERR)
 * Step 3 - to set a MappingContext we need to initialize Enhanced Input Local Player Subsystem, 
 *			check existence and set MappingContext with pointer ref
 * Step 4 - set mouse cursor
 * Step 5 - set input mode game&UI (not locking cursor to viewport, not hiding from capture)
 */
void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	check(AuraContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

/* SETUP INPUT COMPONENT()
 * Step 6 - castcheck InputComponent member in PlayerController to Enhanced Input Component
 * Step 7 - bind EnhancedInputComponent to MoveAction with Move()
 */
void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

/* MOVE()
 * Step 8 - need to cache the value obtained from input in a Vector2D type
 * Step 9 - we cache and obtain the controller rotation on Z axis (Yaw) and create a new FRotator 
 * Step 10 - use the forward vector as te axis from the camera to the character and the right vector as well 
 * Step 11 - check if controlled pawn exist
 * Step 12 - call AddMovementInput() on pawn passing axis direction and input value
 * 
 */
void AAuraPlayerController::Move(const ::FInputActionValue& InputActionValue)
{
	const FVector2D InputAxesVector = InputActionValue.Get<FVector2D>();
	const FRotator ControllerYawRotation = FRotator(0.0f, GetControlRotation().Yaw, 0.0f); //ControlledPawn->GetActorRotation().Yaw

	const FVector ForwardDirection = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(ControllerYawRotation).GetUnitAxis(EAxis::Y);
	
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxesVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxesVector.X);
	}
}

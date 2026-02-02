// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"

/*
 * Step 1 - ensure replication for this class
 */
AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

/*
 * Step 2 - check if AuraContext exists (FATAL ERR)
 * Step 3 - to set a MappingContext we need to initialize Enhanced Input Local Player Subsystem, 
 *			check existence and set MappingContext with pointer ref
 * Step 4 - set mouse cursor
 * Step 5 - set input mode game and UI (not locking to viewport, not hiding from capture)
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

// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"

/* CONSTRUCTOR
 * Step 1 - Setup SpringArm component
 * Step 2 - Setup Camera component
 * Step 3 - Setup CharacterMovement component (inherited from Character class)
 * Step 4 - Deactivate Controller Rotation on the class
 */
AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetRelativeRotation(FRotator(-45.f, 0.f, 0.0f));
	SpringArmComponent->TargetArmLength = 750.f;
	SpringArmComponent->bUsePawnControlRotation = false;
	SpringArmComponent->bEnableCameraLag = true;
	SpringArmComponent->bInheritPitch = false;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bInheritYaw = false;
	SpringArmComponent->SetupAttachment(RootComponent);
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->bUsePawnControlRotation = false;
	Camera->SetupAttachment(SpringArmComponent);
}

/* POSSESSED BY()
 * is called on server when player controller is ready
 * Step.9 - initialize ASC Actor Info
 */
void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	InitAbilityActorInfo();
}

/* ONREP_PLAYERSTATE()
 * is called on client after player controller is ready on server
 * Step.10 - initialize ASC Actor Info
 */
void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	InitAbilityActorInfo();
}

/* POSSESSED BY()
 * This function is used to initialize AbilitySystemComponent with actor info on the Server 
 * Step.5 - get PlayerState from character and check it
 * Step.6 - assign AuraPlayerState ASC to ASC of this class (AbilitySystemComponent)
 * Step.7 - assign AuraPlayerState AS to AS of this class (AttributeSet)
 * Step.8 - Initialize AbilitySystemComponent with actor info function "InitAbilityActorInfo(owner, avatar)"
 */
void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState =  GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
	AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);
}

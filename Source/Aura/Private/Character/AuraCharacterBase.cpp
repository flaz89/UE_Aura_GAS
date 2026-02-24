// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterBase.h"

#include "AbilitySystemComponent.h"

/*
 * Constructor:
 * Step.1 - Initialized Weapon component, attached to character socket and disable collisions
 */
AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

/* GET ABILITY SYSTEM COMPONENT
 * Step.2 - return AbilitySystemComponent declared in .h
 */
UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

/* GET ATTRIBUTE SET
 * Step.3 - return AttributeSet declared in .h
 */
UAttributeSet* AAuraCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

/* INIT ABILITY ACTOR INFO()
 * This function is used to initialize AbilitySystemComponent with actor info on the Server and it's defined in children classes
 * Step.4 - declare and define function
 */
void AAuraCharacterBase::InitAbilityActorInfo()
{
}

/* APPLY EFFECT TO SELF()
 * function refactored for apply general Gameplay Effect
 * Step.11 - declare and define function
 * Step.12 - check if ASC is valid and if DataPrimaryAsset exists
 * Step.13 - create the Context Handle from ASC using MakeEffectContext() function
 * Step.14 - create the Spec Handle from ASC using MakeOutgoingSpec() function
 * Step.15 - apply gameplay effect spec to ASC using ApplayGameplayEffectSpecToTarget() function
 */
void AAuraCharacterBase::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect> GameplayEffectClass, const float Level) const
{
	check(IsValid(GetAbilitySystemComponent()))
	check(GameplayEffectClass)
	
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

/* INITIALIZE PRIMARY ATTRIBUTES()
 * called to initialize RPG primary attributes on AttributeSet
 * Step.5 - declare and define function
 * Step.6 - check if ASC is valid and if DataPrimaryAsset exists
 * Step.7 - create the Context Handle from ASC using MakeEffectContext() function
 * Step.8 - create the Spec Handle from ASC using MakeOutgoingSpec() function
 * Step.16 - comment out the code because transferred to ApplyEffectToSelf() function
 * 
 */
/*void AAuraCharacterBase::InitializePrimaryAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()))
	check(DefaultPrimaryAttributes)
	
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}*/

/* INITIALIZE SECONDARY ATTRIBUTES()
 * called to initialize secondary attributes only after the primary attributed are set
 * Step.10 - declare and define function
 * Step.17 - comment out the code 
 */
/*void AAuraCharacterBase::InitializeSecondaryAttributes() const
{
	
}*/

/* INITIALIZE DEFAULT ATTRIBUTES()
 * Step.18 - declare and define function
 * Step.19 - call the function "ApplyEffetctToSelf()" passing in the DefaultPrimaryAttributes class
 * Step.20 - call the function "ApplyEffetctToSelf()" passing in the DefaultSecondaryAttributes class
 */
void AAuraCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes);
	ApplyEffectToSelf(DefaultSecondaryAttributes);
}

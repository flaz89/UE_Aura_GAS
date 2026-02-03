// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

/* CONSTRUCTOR
 * Step.1 - call built-in function SetNetUpdateFrequency() to set frequency replication of this class
 * Step.2 - construct AbilitySystemComponent with custom type "UAuraAbilitySystemComponent" and set replicated
 * Step.3 - construct AttributeSet with custom type "UAuraAttributeSet"
 */
AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	
	SetNetUpdateFrequency(100.f);
}

/* GET ABILITY SYSTEM COMPONENT
 * Step.4 - return AbilitySystemComponent declared in .h
 */
UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

/* GET ATTRIBUTE SET
 * Step.5 - return AttributeSet declared in .h
 */
UAttributeSet* AAuraPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

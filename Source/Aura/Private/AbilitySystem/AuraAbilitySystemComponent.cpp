// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemComponent.h"

/* ABILITY ACTOR INFO SET()
 * function called after AbilityActorInfo has been set on ASC
 * Step.2 - declare and define
 * Step.3 - bind EffectApplied() function to ASC delegate OnGameplayEffectAppliedDelegateToSelf
 */
void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

/* EFFECT APPLIED()
 * callback function for ASC delegate OnGameplayEffectAppliedDelegateToSelf call after gameplay effect is applied
 * Step.1 - declare and define
 */
void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(1, 8.f, FColor::Blue, FString("Effect Applied"));
}

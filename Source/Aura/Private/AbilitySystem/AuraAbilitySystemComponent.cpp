// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemComponent.h"

/* ABILITY ACTOR INFO SET()
 * function called after AbilityActorInfo has been set on ASC and is called when an effect or more are applied to this ASC
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
 * Step.4 - declare a TagContainer used to store all the asset tags 
 * Step.5 - call GetAllAssetTag() on EffectSpec passing in the tag container
 * Step.6 - loop through TagContainer
 * Step.7 - use the delegate EffectAssetTags to broadcast to WidgetController the TagContainer
 */
void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	
	EffectAssetTags.Broadcast(TagContainer);
}

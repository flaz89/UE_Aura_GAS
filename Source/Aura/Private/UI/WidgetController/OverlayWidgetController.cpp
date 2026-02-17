// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

/* BROADCAST INITIAL VALUES()
 * initialization values function called in HUD after initialized OverlayWidget
 * Step.1 - remove Super:: from parent class if present
 * Step.2 - create a const pointer AuraAttribute set casting inherited member variable AttributeSet
 * Step.3 - call delegate to broadcast Health value from AuraAttributeSet
 * Step.4 - call delegate to broadcast MaxHealth value from AuraAttributeSet
 * Step.13 - call delegate to broadcast Mana value from AuraAttributeSet
 * Step.14 - call delegate to broadcast MaxMana value from AuraAttributeSet
 */
void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	
	OnHealthChange.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChange.Broadcast(AuraAttributeSet->GetMaxHealth());
	
	OnManaChange.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChange.Broadcast(AuraAttributeSet->GetMaxMana());
}

/* BIND CALLBACKS TO DEPENDENCIES()
 * function that lists all the callbacks functions for each attribute changes value, called directly within broadcast
 * Step.5 - remove Super
 * Step.6 - create a const pointer AuraAttribute set casting inherited member variable AttributeSet
 * Step.9 - call the ASC delegate to register Health attribute from AttributeSet, binding the callback HealthChanged
 * Step.10 - call the ASC delegate to register MaxHealth attribute from AttributeSet, binding the callback maxHealthChanged
 * Step.17 - call the ASC delegate to register Mana attribute from AttributeSet, binding the callback ManaChanged
 * Step.18 - call the ASC delegate to register MaxMana attribute from AttributeSet, binding the callback MaxManaChanged
 * Step.21 - use lambda function to catch the reference list of asset tags sent from AbilitySystemComponent
 * Step.25 - inside lambda for each tag inside the asset tags list received call the Function GetDataTableRowByTag and store it in a variable 
 * Step.26 - inside the loop check first if the tag iterating contain a "Message" tag, if so gather information from data table row
 * Step.27 - substitute che callback functions with Lambda Functions
 */
void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute())
							/*.AddUObject(this, &UOverlayWidgetController::HealthChanged)*/
							.AddLambda(
								[this](const FOnAttributeChangeData& Data)
								{
									OnHealthChange.Broadcast(Data.NewValue);
								});
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute())
							/*.AddUObject(this, &UOverlayWidgetController::MaxHealthChanged)*/
							.AddLambda([this](const FOnAttributeChangeData& Data)
							{
								OnMaxHealthChange.Broadcast(Data.NewValue);
							});
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute())
							/*.AddUObject(this, &UOverlayWidgetController::ManaChanged)*/
							.AddLambda([this](const FOnAttributeChangeData& Data)
							{
								OnManaChange.Broadcast(Data.NewValue);
							});
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute())
							/*.AddUObject(this, &UOverlayWidgetController::MaxManaChanged)*/
							.AddLambda([this](const FOnAttributeChangeData& Data)
							{
								OnMaxManaChange.Broadcast(Data.NewValue);
							});
	
	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}

/* HEALTH CHANGED()
 * Step.7 - define this callback function
 * step.11 - call OnHealthChanged delegate and broadcast the new value 
 * Step.28 - remove it
 */
// void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const { OnHealthChange.Broadcast(Data.NewValue); }

/* MAX HEALTH CHANGED()
 * Step.8 - define this callback function
 * Step.12 - call OnMaxHealthChanged delegate and broadcast the new value 
 * Step.29 - remove it
 */
// void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const { OnMaxHealthChange.Broadcast(Data.NewValue); }

/* MANA CHANGED()
 * Step.15 - define this callback function
 * Step.19 - call OnManaChanged delegate and broadcast the new value 
 * Step.30 - remove it
 */
// void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const { OnManaChange.Broadcast(Data.NewValue); }

/* MAX MANA CHANGED()
 * Step.16 - define this callback function
 * Step.20 - call OnMaxManaChanged delegate and broadcast the new value
 * Step.31 - remove it
 */
// void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const { OnMaxManaChange.Broadcast(Data.NewValue); }

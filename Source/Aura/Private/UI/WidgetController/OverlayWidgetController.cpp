// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"

/* BROADCAST INITIAL VALUES()
 * Step.1 - remove Super:: from parent class if present
 * Step.2 - create a const pointer AuraAttribute set casting inherited member variable AttributeSet
 * Step.3 - call delegate to broadcast Health value from AuraAttributeSet
 * Step.4 - call delegate to broadcast MaxHealth value from AuraAttributeSet
 */
void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	OnHealthChange.Broadcast(AuraAttributeSet->GetMaxHealth());
	OnMaxHealthChange.Broadcast(AuraAttributeSet->GetMaxHealth());
}

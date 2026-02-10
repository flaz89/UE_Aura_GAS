// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

/* CONSTRUCTOR()
 * 
 */
UAuraAttributeSet::UAuraAttributeSet()
{
	// functions given from ACCESSORS
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(50.f);
}

/* ONREP_HEALTH()
 * callback function called when attribute "Health" get changes
 * Step.1 - call "gameplayAttrinute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Health, OldHealth);
}

/* ONREP_MAXHEALTH()
 * callback function called when attribute "MaxHealth" get changes
 * Step.3 - call "gameplayAttrinute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxHealth, OldMaxHealth);
}

/* ONREP_MANA()
 * callback function called when attribute "Mana" get changes
 * Step.4 - call "gameplayAttrinute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Mana, OldMana);
}

/* ONREP_MAXMANA()
 * callback function called when attribute "MaxMana" get changes
 * Step.4 - call "gameplayAttrinute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxMana, OldMaxMana);
}

/* GET LIFETIME REPLICATION PROPS()
 * called after AttributeSet construction, used to determine the place where we register variables for replication
 * Step.2 - register attribute "Health" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.3 - register attribute "MaxHealth" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.4 - register attribute "Mana" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.5 - register attribute "MaxMana" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 */
void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

/* CONSTRUCTOR()
 * Step.5 - use ACCESSOR Init to initialize GameplayAttribute data declared in .h
 * Step.48 - comment out InitMaxHealth and InitMaxMana because they are set by GameplayEffect in w/ SecondaryAttributes
 */
UAuraAttributeSet::UAuraAttributeSet()
{
	// functions given from ACCESSORS
	InitHealth(10.f);
	InitMana(25.f);
	//InitMaxHealth(100.f);
	//InitMaxMana(50.f);
}

/* ONREP_HEALTH()
 * callback function called when attribute "Health" get changes
 * Step.1 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Health, OldHealth);
}

/* ONREP_MAXHEALTH()
 * callback function called when attribute "MaxHealth" get changes
 * Step.2 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxHealth, OldMaxHealth);
}

/* ONREP_MANA()
 * callback function called when attribute "Mana" get changes
 * Step.3 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Mana, OldMana);
}

/* ONREP_MAXMANA()
 * callback function called when attribute "MaxMana" get changes
 * Step.4 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxMana, OldMaxMana);
}

/* ONREP_STRENGTH()
 * callback function called when attribute "Strength" get changes
 * Step.24 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Strength, OldStrength);
}

/* ONREP_INTELLIGENCE()
 * callback function called when attribute "Intelligence" get changes
 * Step.26 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Intelligence, OldIntelligence);
}

/* ONREP_RESILIENCE()
 * callback function called when attribute "Resilience" get changes
 * Step.28 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_Resilience(const FGameplayAttributeData& OldResilience) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Resilience, OldResilience);
}

/* ONREP_VIGOR()
 * callback function called when attribute "Vigor" get changes
 * Step.30 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_Vigor(const FGameplayAttributeData& OldVigor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Vigor, OldVigor);
}

/* ONREP_ARMOR()
 * callback function called when attribute "Armor" get changes
 * Step.32 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Armor, OldArmor);
}

/* ONREP_ARMOR PENETRATION()
 * callback function called when attribute "ArmorPenetration" get changes
 * Step.34 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, ArmorPenetration, OldArmorPenetration);
}

/* ONREP_BLOCK CHANCE()
 * callback function called when attribute "BlockChance" get changes
 * Step.36 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, BlockChance, OldBlockChance);
}

/* ONREP_CRITICAL HIT CHANCE()
 * callback function called when attribute "CriticalHitChance" get changes
 * Step.38 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, CriticalHitChance, OldCriticalHitChance);
}

/* ONREP_CRITICAL HIT DAMAGE()
 * callback function called when attribute "CriticalHitDamage" get changes
 * Step.40 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, CriticalHitDamage, OldCriticalHitDamage);
}

/* ONREP_CRITICAL HIT RESISTENCE()
 * callback function called when attribute "CriticalHitResistence" get changes
 * Step.42 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Resilience, OldCriticalHitResistance);
}

/* ONREP_HEALTH REGENERATION()
 * callback function called when attribute "HealthRegeneration" get changes
 * Step.44 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, HealthRegeneration, OldHealthRegeneration);
}

/* ONREP_MANA REGENERATION()
 * callback function called when attribute "ManaRegeneration" get changes
 * Step.46 - call "gameplayAttribute" macro to inform AbilitySystem about attribute replication
 */
void UAuraAttributeSet::OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, ManaRegeneration, OldManaRegeneration);
}

/* GET LIFETIME REPLICATION PROPS()
 * called after AttributeSet construction, used to determine the place where we register variables for replication
 * Step.6 - register attribute "Health" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.7 - register attribute "MaxHealth" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.8 - register attribute "Mana" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.9 - register attribute "MaxMana" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.25 - register attribute "Strength" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.27 - register attribute "Intelligence" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.29 - register attribute "Resilience" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.31 - register attribute "Vigor" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.33 - register attribute "Armor" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.35 - register attribute "ArmorPenetration" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.37 - register attribute "BlockChance" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.39 - register attribute "CriticalHitChance" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.41 - register attribute "CriticalHitDamage" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.43 - register attribute "CriticalHitResistence" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.45 - register attribute "HealthRegeneration" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 * Step.47 - register attribute "ManaRegeneration" with DOREPLIFETIME macro (class, attribute, condition, replication mode)
 */
void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	// primary
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Resilience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Vigor, COND_None, REPNOTIFY_Always);
	
	//secondary
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, ArmorPenetration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, BlockChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, CriticalHitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, CriticalHitDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, CriticalHitResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, HealthRegeneration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, ManaRegeneration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	
	// vital
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	
}

/* PRE ATTRIBUTE CHANGE()
 * This function kicked off each time an attribute change and is called just before the change occur (raccomanded just for clamping)
 * Step.10 - define overridden function from AttributeSet class
 * Step.11 - we can check if the attribute passed in is == to a specific attribute and clamp the NewValue within 0 and MaxValue
 */
void UAuraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}

	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

/* SET EFFECT PROPERTIES()
 * Step.12 - access to Data and obtain the Gameplay Effect Context and set the value in the struct
 * Step.13 - obtain the Ability System Component from the source EffectContext and set the value in the struct
 * Step.14 - check the validity of SourceASC, the GameplayAbilityActorInfo struct of the owner (ActorInfo) and the Actor cached in avatar and set the value in the struct
 * Step.15 - store the Avatar Actor as SourceActor and the Avatar PlayerController as SourceController and set the value in the struct
 * Step.16 - check the case if SourceController is null and SourceActor exists, we can get the controller directly from the pawn father of the actor and set the value in the struct
 * Step.17 - if SourceControl exist we can access and store the possessed character and set the value in the struct
 * Step.18 - to access TargetActor we have to check if AbilityActor info is valid and if target AvatarActor is valid as well and set the value in the struct
 * Step.19 - we che access and store the TargetAvatarActor, TargetController, the TargetCharacter and the TargetAbilitySystemComponent and set the value in the struct
 * 
 */
FEffectProperties UAuraAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data,
	FEffectProperties& Props) const
{
	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();
	
	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo.Get()->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor)) Props.SourceController = Pawn->GetController();
		}
		if (Props.SourceController)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}
	
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
	
	return Props;
}

/* POST GAMEPLAY EFFECT EXECUTE()
 * This function is executed after a gameplay effect change attribute
 * Step.20 - declare a struct FEffectProperties
 * Step.21 - call the function SetEffectProperties() passing in Data and Props (from here we can access to Source and Target of Effect)
 * Step.22 - check if the data passed in is the health attribute, if so clamp appropriately Health value
 * Step.23 - check if the data passed in is the mana attribute, if so clamp appropriately Mana value
 */
void UAuraAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	FEffectProperties Props;
	SetEffectProperties(Data, Props);
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
}



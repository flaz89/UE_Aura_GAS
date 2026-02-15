// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"

/* CONSTRUCTOR
 * Step.1 - set tick to false
 * Step.2 - construct mesh component and set as root
 * Step.3 - construct sphere collision and attach to mesh component
 * Step.14 - remove mesh and sphere collision in order to be more flexible and add them in blueprint
 * Step.18 - create a USceneComponent directly in the constructor and set it as root
 */
AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	//Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	//SetRootComponent(Mesh);
	//Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	//Sphere->SetupAttachment(Mesh);
	
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

/* BEGIN PLAY
 * Step.5 - bind "OnComponentBeginOverlap()" with member function OnOverlap()
 * Step.7 - bind "OnComponentEndOverlap()" with member function EndOverlap()
 * Step.15 - delete Sphere delegate calls
 */
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	//Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnOverlap);
	//Sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::EndOverlap);
}

/* APPLY EFFECT TO TARGET()
 * function used to apply effect from UGameplayEffect class to a specific target
 * Step.19 - call the static function (instead the classic process to check te interface) to obtain and store the ASC
 * Step.20 - check if AbilitySystemComponent is null pointer on target actor
 * Step.21 - check GameplayEffectClass
 * Step.21 - create a struct FGameplayEffectContextHandle (wrapper) with the return of value of ASC function MakeEffectContext()
 * Step.22 - register this object to EffectContextHandle creating a context object
 * Step.23 - create a structure FGameplayEffectSpecHandle (wrapper) and store value from MakeOutgoingSpec() function
 * Step.24 - call ApplyGameEffectSpecToSelf() on ASC obtained from taget passing in the dereferenced data from EffectSpectHandle
 * Step.29 - create a bool variable bIsInfinite extracting and comparing the policy duration value of GameplayEffect from the EffectSpecHandle
 * Step.30 - store the return of function ApplyGameplayEffectSpecToSelf in a variable 
 * Step.31 - check if duration policy is infinite and if the removal policy of GameplayEffect removal policy enum is set to RemoveOnEndOverlap
 * Step.32 - if true add to ActiveEffectHandles map the active effect and Target ability system component
 * Step.41 - Add ActorLevel variable to MakeOutgoingSpec() function
 */
void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;
	
	check(GameplayEffectClass)
	
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, ActorLevel, EffectContextHandle);
	const FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	
	const bool bIsInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;
	if (bIsInfinite && InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		ActiveEffectHandles.Add(ActiveEffectHandle, TargetASC);
	}
}

/* ON OVERLAP
 * Step.25 - if InstantEffectApplicationPolicy is set to "OnOverlap" call the function ApplyEffectToTarget 
			 passing target actor and InstantGameplayEffect class stored in .h
 * Step.27 - if DurationEffectApplicationPolicy is set to "OnOverlap" call the function ApplyEffectToTarget 
			 passing target actor and DurationGameplayEffect class stored in .h
 * Step.33 - if InfiniteEffectApplicationPolicy is set to "OnOverlap" call the function ApplyEffectToTarget 
			 passing target actor and InfiniteGameplayEffect class stored in .h
 */
void AAuraEffectActor::OnOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
}

/* ON END OVERLAP
 * Step.26 - if InstantEffectRemovalPolicy is set to "OnEndOverlap" call the function ApplyEffectToTarget 
			 passing target actor and InstantGameplayEffect stored in .h
 * Step.28 - if DurationEffectRemovalPolicy is set to "OnEndOverlap" call the function ApplyEffectToTarget 
			 passing target actor and DurationGameplayEffect class stored in .h
 * Step.34 - if InfiniteEffectApplicationPolicy is set to "OnEndOverlap" call the function ApplyEffectToTarget 
			 passing target actor and InfiniteGameplayEffect class stored in .h	
 * Step.35 - if InfiniteEffectApplicationPolicy is set to "OnOverlap" call the function ApplyEffectToTarget 
			 passing target actor and InfiniteGameplayEffect class stored in .h
 * Step.36 - if InfiniteEffectRemovalPolicy is set to "OnEndOverlap" first of all obtain the Target Ability System Component and check if is valid	
 * Step.37 - loop on map and check for each pair if the value is == to target Ability System Component, if so remove the ActiveGameplayEffect using the key of the pair
 * Step.38 - create an array that handles all the ActiveGameplayEffect selected to remove
 * Step.39 - looping through each pair, after removing the ActiveGameplayEffect on Ability System Component, ad that ActiveGameplayEffect to the new array
 * Step.40 - looping through the array contains all ActiveGameplayEffect to remove and for each effect remove in the map that pair with the key containing it
 */
void AAuraEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
	if (InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
		if (!IsValid(TargetASC)) return;
		
		TArray<FActiveGameplayEffectHandle> HandlesToRemove; 
		for (const auto HandlePair : ActiveEffectHandles)
		{
			if (HandlePair.Value == TargetASC)
			{
				TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, 1); //stackToRemove = 1 if you want remove just a single effect 
				HandlesToRemove.Add(HandlePair.Key);
			}
		}
		
		for (FActiveGameplayEffectHandle& Handle : HandlesToRemove)
		{
			ActiveEffectHandles.FindAndRemoveChecked(Handle);
		}
	}
}

/* ON OVERLAP()
 * called by delegate function "OnComponentBeginOverlap" and used to access attribute set and modify attribute
 * Step.4 - define function
 * Step.8 - verify if OtherActor implement IAbilitySystemInterface
 * Step.9 - obtain AuraAttributeSet reference from ASC of OtherActor implementing interface
 * Step.10 - use const_cast just to test and remove the constness from AuraAttributeSet
 * Step.11 - change Health attribute
 * Step.12 - Destroy actor at the end of the process
 * Step.13 - change Mana attribute
 * Step.16 - remove function delegate
 */
/*void AAuraEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO change this to apply Gameplay Effect. For now, using const_Cast as hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor)) 
	{
		const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));
		UAuraAttributeSet* MutableAuraAttributeSet= const_cast<UAuraAttributeSet*>(AuraAttributeSet);
		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
		MutableAuraAttributeSet->SetMana(AuraAttributeSet->GetMana() - 25.f);
		Destroy();
	}
}*/

/* ON END OVERLAP()
 * called by delegate function "OnComponentEndOverlap"
 * Step.6 - define function
 * Step.17 - remove function delegate
 */
/*	void AAuraEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
	{
	}
*/



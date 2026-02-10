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
 */
void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (TargetASC == nullptr) return;
	
	check(GameplayEffectClass == nullptr)
	
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
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



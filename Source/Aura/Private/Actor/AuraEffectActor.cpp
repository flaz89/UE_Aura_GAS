// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/AuraEffectActor.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Character/AuraCharacter.h"
#include "Components/SphereComponent.h"

/* CONSTRUCTOR
 * Step.1 - set tick to false
 * Step.2 - construct mesh component and set as root
 * Step.3 - construct sphere collision and attach to mesh component
 */
AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(Mesh);
}

/* BEGIN PLAY
 * Step.5 - bind "OnComponentBeginOverlap()" with member function OnOverlap()
 * Step.7 - bind "OnComponentEndOverlap()" with member function EndOverlap()
 */
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::EndOverlap);
}

/* ON OVERLAP()
 * called by delegate function "OnComponentBeginOverlap" and used to access attribute set and modify attribute
 * Step.4 - define function
 * Step.8 - verify if OtherActor implement IAbilitySystemInterface
 * Step.9 - obtain AuraAttributeSet reference from ASC of OtherActor implementing interface
 * Step.10 - use const_cast just to test and remove the constness from AuraAttributeSet and change its attribute
 * Step.11 - Destroy actor at the end of the process
 */
void AAuraEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO change this to apply Gameplay Effect. For now, using const_Cast as hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor)) 
	{
		const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));
		UAuraAttributeSet* MutableAuraAttributeSet= const_cast<UAuraAttributeSet*>(AuraAttributeSet);
		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

/* ON END OVERLAP()
 * called by delegate function "OnComponentEndOverlap"
 * Step.6 - define function
 */
void AAuraEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}



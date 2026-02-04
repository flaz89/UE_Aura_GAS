// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

/* CONSTRUCTOR
 * Step.4 - set collision response to block visibility for skeletal-mesh (mouse can trace it)
 * Step.5 - construct AbilitySystemComponent with custom type "UAuraAbilitySystemComponent" and set replicated
 * Step.6 - construct AttributeSet with custom type "UAuraAttributeSet"
 * Step.7 - set AbilitySystemComponent replication mode to Minimal (cause is AI) 
 */
AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}


/* BEGIN PLAY()
 * Step.8 - Initialize AbilitySystemComponent with actor info function "InitAbilityActorInfo(owner, avatar)"
 */
void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

/* HIGHLIGHT ACTOR
 * Step.1 - Get Skeletal-mesh and enable RenderCustomDepth and set the custom stencil pass value
 * Step.2 - Get Weapon and enable RenderCustomDepth and set the custom stencil pass value
 */
void AAuraEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

/* UNHIGHLIGHT ACTOR
 * Step.3 - Disable RenderCustomDepth for Skeletal-mesh and Weapon
 */
void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

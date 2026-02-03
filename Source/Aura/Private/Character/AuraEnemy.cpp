// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

/* CONSTRUCTOR
 * Step.4 - set collision response to block visibility for skeletal-mesh (mouse can trace it)
 * Step.5 - construct AbilitySystemComponent with custom type "UAuraAbilitySystemComponent" and set replicated
 * Step.6 - construct AttributeSet with custom type "UAuraAttributeSet"
 */
AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	
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

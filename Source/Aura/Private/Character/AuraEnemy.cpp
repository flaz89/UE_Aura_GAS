// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

#include "Aura/Aura.h"

/* CONSTRUCTOR
 * Step.4 - set collision response to block visibility for skeletalmesh
 */
AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

/* HIGHLIGHT ACTOR
 * Step.1 - Get Skeletalmesh and enable RenderCustomDepth and set the custom stencil pass value
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
 * Step.3 - Disable RenderCustomDepth for Skeletalmesh and Weapon
 */
void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

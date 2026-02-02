// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterBase.h"

/*
 * Constructor:
 * Step.1 - Initialized Weapon component, attached to character socket and disable collisions
 */
AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


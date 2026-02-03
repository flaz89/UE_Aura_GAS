// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

/* CONSTRUCTOR
 * Step.1 - Call built-in function SetNetUpdateFrequency() to set frequency replication of this class
 */
AAuraPlayerState::AAuraPlayerState()
{
	SetNetUpdateFrequency(100.f);
}

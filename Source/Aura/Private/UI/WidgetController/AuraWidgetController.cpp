// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AuraWidgetController.h"

/* SET WIDGET CONTROL PARAMS()
 * Step.1 - assign struct values to member variable
 */
void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

/* BROADCAST INITIAL VALUES()
 * function overrided from child class, used to init the values in widgets (View)
 */
void UAuraWidgetController::BroadcastInitialValues()
{
	
}

/* BIND CLLBACKS TO DEPENDENCIES()
 * function overrided from child class, used to bind callback functions to all dependencies (Controller)
 */
void UAuraWidgetController::BindCallbacksToDependencies()
{
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

/* GET OVERLAY WIDGET CONTROLLER()
 *  Step.1 - check if "OverlayWidgetController" member exists or not, if not create new instance one
 *  Step.2 - Set params structure on "OverlayWidgetController" instance and then return it
 *  Step.12 - Call the delegate function on WidgetController that binds callbacks functions on values change
 */
UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
		
		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

/* INIT OVERLAY()
 * Step.3 - check if "OverlayWidgetClass" member exists (View)
 * Step.4 - check if "OverlayWidgetControllerClass" member exists (Controller)
 * Step.5 - create generic UUserWidget widget
 * Step.6 - assign cast widget to "OverlayWidget" member
 * Step.7 - define "WidgetControllerParams" struct with arguments passed by
 * Step.8 - assign the function return "GetOverlayWidgetController()" to a local pointer "WidgetController"
 * Step.9 - use member function "SetWidgetController()" of member "OverlayWidget" to set the proper controller
 * Step.10 - add OverlayWidget to viewport
 * Step.11 - call BroadcastInitialValues on widget controller
 */
void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AuraHUD"))
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_AuraHUD"))
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);
	
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	
	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	
	OverlayWidget->AddToViewport();
}

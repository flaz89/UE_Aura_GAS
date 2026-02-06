// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

/* GET OVERLAY WIDGET CONTROLLER()
 *  Step.1 - check if "OverlayWidgetController" member exists or not, if not create new instance one
 *  Step.2 - Set params structure on "OverlayWidgetController" instance and then return it
 */
UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		
		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

/* INIT OVERLAY()
 * Step.3 - check if "OverlayWidgetClass" member exists (View)
 * Step.4 - check if "OverlayWidgetControllerClass" member exists (Controller)
 * Step.5 - create generic UUserWidget widget
 * Step.6 - assign cast widget to "OverlayWidget" memeber
 * Step.7 - define "WidgetControllerParams" struct with arguments passed by
 * Step.8 - assign the function return "GetOverlayWidgetController()" to a local pointer "WidgetController"
 * Step.9 - use member function "SetWidgetController()" of member "OverlayWidget" to set the proper controller
 * Step.10 - add created widget to viewport
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
	
	Widget->AddToViewport();
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/AuraUserWidget.h"

/* SET WIDGET CONTROLLER()
 * Step.1 - declare this function
 * Step.2 - set the WidgetController member with argument passed calling function
 * Step.3 - call function WidgetControllerSet() ;
 */
void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet(); // the moment we call this function we know the WidgetController has been set
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/AuraUserWidget.h"

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();
	
	UAuraUserWidget* HUDWidget = CreateWidget<UAuraUserWidget>(GetWorld(), OverlayWidgetClass);
	HUDWidget->AddToViewport();
}

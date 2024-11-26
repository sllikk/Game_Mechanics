// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FlashLightComponent.h"

UFlashLightComponent::UFlashLightComponent(): blsFlashVisible(false)
{
}

void UFlashLightComponent::BeginPlay()
{
	Super::BeginPlay();
	this->SetVisibility(false);

}

void UFlashLightComponent::ToggleFlashLight()
{
	blsFlashVisible = this->IsVisible();

	if (blsFlashVisible == true)
	{
		this->SetVisibility(false);
	}
	else
	{
		this->SetVisibility(true);
	}
}


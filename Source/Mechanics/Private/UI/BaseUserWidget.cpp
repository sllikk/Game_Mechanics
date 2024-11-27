// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseUserWidget.h"
#include "Components/ProgressBar.h"
#include "Player/HealthComponent.h"
#include "Player/StaminaComponent.h"


void UBaseUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	check(HealthBar != nullptr && StaminaBar != nullptr)

	if (HP != nullptr && Stamina != nullptr)
	{
		HealthBar->SetPercent(HP->GetCurrentHealth() / HP->GetMaxHealth());
		StaminaBar->SetPercent(Stamina->GetCurrentStamina() / Stamina->GetMaxStamina());
	}
}

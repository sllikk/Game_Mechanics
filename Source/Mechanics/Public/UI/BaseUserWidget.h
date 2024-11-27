// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "BaseUserWidget.generated.h"

class UProgressBar;
class UHealthComponent;
class UStaminaComponent;

UCLASS(Abstract)
class MECHANICS_API UBaseUserWidget : public UCommonUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true", BindWidget))
	TObjectPtr<UProgressBar> HealthBar;

	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true", BindWidget))
	TObjectPtr<UProgressBar> StaminaBar;

protected:	

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY()
	TObjectPtr<UHealthComponent> HP;
	UPROPERTY()
	TObjectPtr<UStaminaComponent> Stamina;
	
public:	

	//void SetHealthUI(float CurrentHP, float MaxHP) const;
	//void SetStaminaUI(float CurrentStamina, float MaxStamina) const;

	
	void SetHealthUI(UHealthComponent* hp);
	void SetStaminaUI(UStaminaComponent* stamina);
};

FORCEINLINE void UBaseUserWidget::SetHealthUI(UHealthComponent* hp)
{
	HP = hp;
}

FORCEINLINE void UBaseUserWidget::SetStaminaUI(UStaminaComponent* stamina)
{
	Stamina = stamina;
}


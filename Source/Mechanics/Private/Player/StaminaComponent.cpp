// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/StaminaComponent.h"

DEFINE_LOG_CATEGORY(LogStamina)

// Sets default values for this component's properties
UStaminaComponent::UStaminaComponent(): MaxStamina(100), StaminaRegenRate(20.0f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentStamina = MaxStamina;

	StaminaDrainRates.Add(EStaminaDrainType::NONE, 0.0f);
	StaminaDrainRates.Add(EStaminaDrainType::SPRINT, 15.0f);
	StaminaDrainRates.Add(EStaminaDrainType::JUMP, 20.0f);
	StaminaDrainRates.Add(EStaminaDrainType::ATTACK, 1);
	StaminaDrainRates.Add(EStaminaDrainType::ANOMALY, 2);
	StaminaDrainRates.Add(EStaminaDrainType::DAMAGE, 4);
	StaminaDrainRates.Add(EStaminaDrainType::PHYSICS, 6);

}


// Called when the game starts
void UStaminaComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UStaminaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (const EStaminaDrainType& ActionType : ActivateDrainType)
	{
		if (StaminaDrainRates.Contains(ActionType) && CurrentStamina >= 0)
		{
			UseStamina(ActionType, StaminaDrainRates[ActionType] * DeltaTime);	
		}
	}

	if (ActivateDrainType.Num() == 0 && CurrentStamina < MaxStamina)
	{
		CurrentStamina = FMath::Clamp(CurrentStamina + StaminaRegenRate * DeltaTime, 0.0f, MaxStamina);
	}

}

bool UStaminaComponent::HasEnoughStamina(float Cost) const
{
	return CurrentStamina >= Cost;
}

void UStaminaComponent::UseStamina(EStaminaDrainType ActionType, float Amount)
{
	if (CurrentStamina <= 0.f)
	{
		return;
	}

//	if (CurrentStamina <= 0)
//	{
//		OnStaminaDepleted.Broadcast();
//	}

	CurrentStamina = FMath::Clamp(CurrentStamina - Amount, 0.0f, MaxStamina);
	
	
}

void UStaminaComponent::StartStaminaDrainAction(EStaminaDrainType DrainType)
{
	if (!ActivateDrainType.Contains(DrainType) && ActivateDrainType.Num() <= 0)
	{
		ActivateDrainType.Add(DrainType);
	}
	
}

void UStaminaComponent::StopStaminaDrainAction(EStaminaDrainType DrainType)
{
	ActivateDrainType.Remove(DrainType);
}



// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Player/EAttribute.h"
#include "StaminaComponent.generated.h"

class ABasePlayer;

DECLARE_LOG_CATEGORY_EXTERN(LogStamina, Log, All)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStaminaDepleted);

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHANICS_API UStaminaComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stamina", meta=(AllowPrivateAccess  = "true"))
	float MaxStamina;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Stamina", meta=(AllowPrivateAccess  = "true"))
	float CurrentStamina;	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stamina", meta=(AllowPrivateAccess = "true"))
	float StaminaRegenRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category="StaminaMap", meta=(AllowPrivateAccess = "true"))	
	TMap<EStaminaDrainType, float > StaminaDrainRates;

	UPROPERTY()
	TSet<EStaminaDrainType> ActivateDrainType;
	
public:	
	// Sets default values for this component's properties
	UStaminaComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:	

	UFUNCTION(BlueprintCallable, Category="Stamina")
	bool HasEnoughStamina(float Cost) const;

	UFUNCTION(BlueprintCallable, Category="Stamina")
	void UseStamina(EStaminaDrainType ActionType, float Amount);

	UPROPERTY(EditAnywhere, Blueprintable, Category="Stamina")
	FStaminaDepleted OnStaminaDepleted;
	
	void StartStaminaDrainAction(EStaminaDrainType DrainType);
	void StopStaminaDrainAction(EStaminaDrainType DrainType);
	
	float GetCurrentStamina() const;
	float GetMaxStamina() const;
	
		
private:

	friend ABasePlayer;
};


FORCEINLINE float UStaminaComponent::GetCurrentStamina() const
{
	return CurrentStamina;
}

FORCEINLINE float UStaminaComponent::GetMaxStamina() const
{
	return MaxStamina;
}


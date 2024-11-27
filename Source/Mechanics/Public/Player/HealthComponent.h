// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogHealth, Log, All);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Config=Game )
class MECHANICS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Health", meta=(AllowPrivateAccess  = "true"))
	float MaxHealth;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Health", meta=(AllowPrivateAccess  = "true"))
	float CurrentHealth;	
	
public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:	

	float GetCurrentHealth() const;
	float GetMaxHealth() const;
	
};

FORCEINLINE float UHealthComponent::GetCurrentHealth() const
{
	return CurrentHealth;
}

FORCEINLINE float UHealthComponent::GetMaxHealth() const
{
	return MaxHealth;
}

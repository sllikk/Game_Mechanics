// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/HealthComponent.h"

DEFINE_LOG_CATEGORY(LogHealth)

// Sets default values for this component's properties
UHealthComponent::UHealthComponent(): MaxHealth(100.0f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentHealth = MaxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogHealth, Log, TEXT("Name: %s"), *GetOwner()->GetName());
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


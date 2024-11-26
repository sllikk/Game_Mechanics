// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RadiationComponent.h"

DEFINE_LOG_CATEGORY(LogRadiation)

// Sets default values for this component's properties
URadiationComponent::URadiationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URadiationComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogRadiation, Log, TEXT("Name: %s"), *GetOwner()->GetName());
	
}


// Called every frame
void URadiationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


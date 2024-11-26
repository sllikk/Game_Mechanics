// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SurvivalComponent.h"

DEFINE_LOG_CATEGORY(LogSurvival)

// Sets default values for this component's properties
USurvivalComponent::USurvivalComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USurvivalComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogSurvival, Log, TEXT("Name: %s"), *GetOwner()->GetName());
	
}


// Called every frame
void USurvivalComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


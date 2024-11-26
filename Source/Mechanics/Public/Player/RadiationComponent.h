// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RadiationComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogRadiation, Log, All)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHANICS_API URadiationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URadiationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:	
	
		
};

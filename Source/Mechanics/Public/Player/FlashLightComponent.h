// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SpotLightComponent.h"
#include "FlashLightComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MECHANICS_API UFlashLightComponent : public USpotLightComponent
{
	GENERATED_BODY()

	UFlashLightComponent();

public:	

	FORCEINLINE bool IsVisibleFlashLight() const { return blsFlashVisible; };
	void ToggleFlashLight();

protected:

	virtual void BeginPlay() override;
	
private:

	
	bool blsFlashVisible;
	
};

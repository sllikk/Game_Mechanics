#pragma once

#include "EAttribute.generated.h"

UENUM(BlueprintType)
enum class EStaminaDrainType : uint8
{
	NONE = 0 UMETA(Hidden),
	SPRINT UMETA(DisplayName="Player Sprint"),
	JUMP UMETA(DisplayName="Player Sprint"),
	ATTACK UMETA(DisplayName="Player attack"),
	DAMAGE UMETA(DisplayName="Player damaged"),
	PHYSICS UMETA(DisplayName="Physics damaged player"),
	ANOMALY UMETA(DisplayName="Player trigger anomaly"),
	INVENTORY UMETA(DisplayName="Max player inventory weight"),
	USE UMETA(DisplayName = "Use obj"),
		
};


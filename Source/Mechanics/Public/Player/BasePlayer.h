// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasePlayer.generated.h"

class UCameraComponent;
class USkeletalMeshComponent;
class UInputAction;
class UInputMappingContext;
class UPhysicsHandleComponent;
class UBaseUserWidget;

class UFlashLightComponent;
class UHealthComponent;
class UStaminaComponent;
class URadiationComponent;
class USurvivalComponent;

struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogPlayer, Log, All)

UCLASS(Config=Game)
class MECHANICS_API ABasePlayer : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess = "true"))
	float MaxSpeedRun;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess = "true"))
	float MaxSpeedWalk;
	
	
#pragma region INPUT_PLAYER
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Move;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Look;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Jump;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Crouch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Sprint;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Grab;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Trow;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_FlashLight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Interact;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputMapping", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> IMC_Player; 

#pragma endregion 	

// FP == First Person 	
#pragma region COMPONENTS

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> pFP_CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> pFP_MeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PhysicsHandle", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UPhysicsHandleComponent> pGrabHandleComponent;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlashLight", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UFlashLightComponent> pFlashLightComponent;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UHealthComponent> pHealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stamina", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UStaminaComponent> pStaminaComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Radiation", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<URadiationComponent> pRadiationComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Survival", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USurvivalComponent> pSurvivalComponent;
	
	
#pragma endregion 	
	
public:
	// Sets default values for this character's properties
	explicit ABasePlayer(const FObjectInitializer& Initializer);
	virtual void PostInitializeComponents() override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called when game end
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:	

	UFUNCTION()
	void DelegateNullStamina();
	
#pragma region INPUT_FUNCTIONS

	void MoveTriggered(const FInputActionValue& ActionValue);	
	void LookTriggered(const FInputActionValue& ActionValue);
	void ToggleFlashLight();
	void SprintStarted();
	void SprintCompleted();
	void CrouchStarted();
	void CrouchCompleted();
	void Interact();
	void ToggleGrab();
	void GrabObject();
	void ReleaseObject();
	void TrowObject();
	
	virtual void Jump() override;
	virtual void StopJumping() override;	
	
#pragma endregion 	

	// UI
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	TSubclassOf<UBaseUserWidget> BaseWidgetClass;
	UPROPERTY()
	TObjectPtr<UBaseUserWidget> PlayerUI;
	
public:	

/*--------------------------------------------------------------------------------------------------------------------*/
	UCameraComponent* GetFpsCameraComponent() const;
	USkeletalMeshComponent* GetFpsMeshComponent() const;		
	UPhysicsHandleComponent* GetGrabComponent() const;
	
private:
	
#if UE_BUILD_DEVELOPMENT || UE_BUILD_DEBUG

	void DebugMovement();
	
#endif
	

	bool blsRunning;
	
};

/*--------------------------------------------------------------------------------------------------------------------*/
											// Getters Setters 
/*--------------------------------------------------------------------------------------------------------------------*/

FORCEINLINE UCameraComponent* ABasePlayer::GetFpsCameraComponent() const
{
	return pFP_CameraComponent;	
}

FORCEINLINE USkeletalMeshComponent* ABasePlayer::GetFpsMeshComponent() const
{
	return pFP_MeshComponent;
}


FORCEINLINE UPhysicsHandleComponent* ABasePlayer::GetGrabComponent() const
{
	return pGrabHandleComponent;
}





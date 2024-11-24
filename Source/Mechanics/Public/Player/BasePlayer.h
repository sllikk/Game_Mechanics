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
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogPlayer, Log, All)

UCLASS(Config=Game)
class MECHANICS_API ABasePlayer : public ACharacter
{
	GENERATED_BODY()

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UPhysicsHandleComponent> pGrabHandleComponent;	
	
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
	
public:	

/*--------------------------------------------------------------------------------------------------------------------*/
	UCameraComponent* GetFpsCameraComponent() const;
	USkeletalMeshComponent* GetFpsMeshComponent() const;		
	UPhysicsHandleComponent* GetGrabComponent() const;
	
	
public:	


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





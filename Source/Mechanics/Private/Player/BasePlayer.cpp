// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/BasePlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetStringLibrary.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Player/FlashLightComponent.h"
#include "Player/HealthComponent.h"
#include "Player/StaminaComponent.h"
#include "Player/RadiationComponent.h"
#include "Player/SurvivalComponent.h"

DEFINE_LOG_CATEGORY(LogPlayer)

ABasePlayer::ABasePlayer(const FObjectInitializer& Initializer)
	:Super(Initializer), pFP_CameraComponent(nullptr), pFP_MeshComponent(nullptr), pGrabHandleComponent(nullptr)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//default settings character movement, mesh and FirstPersonCamera
	GetCapsuleComponent()->InitCapsuleSize(42.5f, 96.0f);

	pFP_CameraComponent = Initializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("Player_CameraComponent"));
	pFP_CameraComponent->SetupAttachment(GetCapsuleComponent());
	pFP_CameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 80.f)); // Position the camera
	pFP_CameraComponent->bUsePawnControlRotation = true;
	pFP_CameraComponent->bCameraMeshHiddenInGame = false;

	pGrabHandleComponent = Initializer.CreateDefaultSubobject<UPhysicsHandleComponent>(this, "Player_PhysicsHandleComponent");
	pFlashLightComponent = Initializer.CreateDefaultSubobject<UFlashLightComponent>(this, TEXT("Player_FlashLightComponent"));	
	pFlashLightComponent->SetupAttachment(pFP_CameraComponent);

	pHealthComponent = Initializer.CreateDefaultSubobject<UHealthComponent>(this, TEXT("Player_HealthComponent"));
	pRadiationComponent = Initializer.CreateDefaultSubobject<URadiationComponent>(this, TEXT("Player_RadiationComponent"));
	pStaminaComponent = Initializer.CreateDefaultSubobject<UStaminaComponent>(this, TEXT("Player_StaminaComponent"));
	pSurvivalComponent = Initializer.CreateDefaultSubobject<USurvivalComponent>(this, TEXT("Player_SurvivalComponent"));
	

}


void ABasePlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	const UWorld* pWorld = GetWorld();
	if (pWorld != nullptr && pWorld->IsGameWorld())
	{
		#if UE_BUILD_DEVELOPMENT || UE_BUILD_DEBUG	

		#endif
	}
	
}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();

	if (const APlayerController* PC = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(IMC_Player, 0);
		}
	}
	
	
		
}

void ABasePlayer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

#if UE_BUILD_DEVELOPMENT || UE_BUILD_DEBUG

	DebugMovement();

#endif
	
}

// Called to bind functionality to input
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ABasePlayer::MoveTriggered);
		EnhancedInput->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ABasePlayer::LookTriggered);
		EnhancedInput->BindAction(IA_Sprint, ETriggerEvent::Started, this, &ABasePlayer::SprintStarted);
		EnhancedInput->BindAction(IA_Sprint, ETriggerEvent::Completed, this, &ABasePlayer::SprintCompleted);
		EnhancedInput->BindAction(IA_Jump, ETriggerEvent::Started, this, &ABasePlayer::Jump);
		EnhancedInput->BindAction(IA_Jump, ETriggerEvent::Completed, this, &ABasePlayer::StopJumping);
		EnhancedInput->BindAction(IA_Crouch, ETriggerEvent::Started, this, &ABasePlayer::CrouchStarted);
		EnhancedInput->BindAction(IA_Crouch, ETriggerEvent::Completed, this, &ABasePlayer::CrouchCompleted);

		EnhancedInput->BindAction(IA_Interact, ETriggerEvent::Started, this, &ABasePlayer::Interact);
		EnhancedInput->BindAction(IA_FlashLight, ETriggerEvent::Started, this, &ABasePlayer::ToggleFlashLight);
		EnhancedInput->BindAction(IA_Grab, ETriggerEvent::Started, this, &ABasePlayer::ToggleGrab);
		EnhancedInput->BindAction(IA_Trow, ETriggerEvent::Started, this, &ABasePlayer::TrowObject);

		// Debug;
		PlayerInputComponent->BindKey(EKeys::G, IE_Pressed, this, &ABasePlayer::DebugMovement);
		
	}
	else
	{
		UE_LOG(LogInput, Error, TEXT("Failed to find an EnhancedInputComponent!"));
	}
	
}

/*--------------------------------------------------------------------------------------------------------------------*/
												/* InputFunc */
/*--------------------------------------------------------------------------------------------------------------------*/

void ABasePlayer::MoveTriggered(const FInputActionValue& ActionValue)
{
	const FVector2D& Direction = ActionValue.Get<FVector2D>(); 
	
	AddMovementInput(GetActorForwardVector(), Direction.Y);
	AddMovementInput(GetActorRightVector(), Direction.X);
}

void ABasePlayer::LookTriggered(const FInputActionValue& ActionValue)
{
	const FVector2D& LookAxisVector2D = ActionValue.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector2D.X);
	AddControllerPitchInput(LookAxisVector2D.Y);
}

void ABasePlayer::Jump()
{
	Super::Jump();

}

void ABasePlayer::StopJumping()
{
	Super::StopJumping();

}

void ABasePlayer::ToggleFlashLight()
{
	if (pFlashLightComponent != nullptr)
	{
		pFlashLightComponent->ToggleFlashLight();
		UE_LOG(LogPlayer, Log, TEXT("State: %s"), *UKismetStringLibrary::Conv_BoolToString(pFlashLightComponent->IsVisibleFlashLight()))
	}
}

void ABasePlayer::SprintStarted()
{

}

void ABasePlayer::SprintCompleted()
{

}

void ABasePlayer::CrouchStarted()
{

}

void ABasePlayer::CrouchCompleted()
{

}

void ABasePlayer::Interact()
{

}

void ABasePlayer::ToggleGrab()
{

}

void ABasePlayer::GrabObject()
{

}

void ABasePlayer::ReleaseObject()
{

}

void ABasePlayer::TrowObject()
{

}

/*--------------------------------------------------------------------------------------------------------------------*/
											/* Debug */
/*--------------------------------------------------------------------------------------------------------------------*/

#if UE_BUILD_DEVELOPMENT || UE_BUILD_DEBUG

void ABasePlayer::DebugMovement()
{
	const UCharacterMovementComponent* pMovement = GetCharacterMovement();
	check(pMovement != nullptr)
	
	const FString& StrMovement = FString::Printf(TEXT("Acceleration: %f, Speed: %s, FlySpeed: %f, JumpZVelocity: %f"),
		pMovement->MaxAcceleration, *pMovement->Velocity.ToString(), pMovement->MaxFlySpeed, pMovement->JumpZVelocity);

	check(GEngine != nullptr)
	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Silver, StrMovement);
}


#endif






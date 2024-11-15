// Copyright Frederik Trampenau All Rights Reserved.

#include "ShootingRangeCharacter.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "SquadGoals/Data/Configs/Input/FirstPersonCharacterInputConfig.h"
#include "SquadGoals/Debug/DebugPrintHelpers.h"

AShootingRangeCharacter::AShootingRangeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
}

void AShootingRangeCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AShootingRangeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveWithInput();
}

void AShootingRangeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	const APlayerController* PlayerController = Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		PlayerController->GetLocalPlayer());
	InputSubsystem->ClearAllMappings();
	InputSubsystem->AddMappingContext(InputMapping, 0);

	if (!InputActions)
	{
		return;
	}
	
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	Input->BindAction(InputActions->MoveVertical, ETriggerEvent::Triggered, this, &AShootingRangeCharacter::ProcessMoveVerticalInput);
	Input->BindAction(InputActions->MoveVertical, ETriggerEvent::Completed, this, &AShootingRangeCharacter::ResetMoveVerticalInput);
	Input->BindAction(InputActions->MoveHorizontal, ETriggerEvent::Triggered, this, &AShootingRangeCharacter::ProcessMoveHorizontalInput);
	Input->BindAction(InputActions->MoveHorizontal, ETriggerEvent::Completed, this, &AShootingRangeCharacter::ResetMoveHorizontalInput);
	Input->BindAction(InputActions->LookVertical, ETriggerEvent::Triggered, this, &AShootingRangeCharacter::ProcessLookVerticalInput);
	Input->BindAction(InputActions->LookVertical, ETriggerEvent::Completed, this, &AShootingRangeCharacter::ResetLookVerticalInput);
	Input->BindAction(InputActions->LookHorizontal, ETriggerEvent::Triggered, this, &AShootingRangeCharacter::ProcessLookHorizontalInput);
	Input->BindAction(InputActions->LookHorizontal, ETriggerEvent::Completed, this, &AShootingRangeCharacter::ResetLookHorizontalInput);
	Input->BindAction(InputActions->Jump, ETriggerEvent::Triggered, this, &AShootingRangeCharacter::ProcessJumpInput);
	Input->BindAction(InputActions->Shoot, ETriggerEvent::Triggered, this, &AShootingRangeCharacter::ProcessShootInput);
}

void AShootingRangeCharacter::MoveWithInput()
{
	FVector2D MoveInputToProcess = { InputData.HorizontalMoveInput, InputData.VerticalMoveInput };
	MoveInputToProcess.Normalize();

	if (MoveInputToProcess.X != 0.0f)
	{
		const FVector Right = GetActorRightVector();
		AddMovementInput(Right, MoveInputToProcess.X);
	}
	if (MoveInputToProcess.Y != 0.0f)
	{
		const FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, MoveInputToProcess.Y);
	}
	
	if (InputData.HorizontalLookInput != 0.0f)
	{
		AddControllerYawInput(InputData.HorizontalLookInput);
	}
	if (InputData.VerticalLookInput != 0.0f)
	{
		AddControllerPitchInput(InputData.VerticalLookInput);
	}
}

void AShootingRangeCharacter::ProcessMoveVerticalInput(const FInputActionValue& InputValue)
{
	InputData.VerticalMoveInput = InputValue.Get<float>();
}

void AShootingRangeCharacter::ResetMoveVerticalInput(const FInputActionValue& InputValue)
{
	InputData.VerticalMoveInput = 0.0f;
}

void AShootingRangeCharacter::ProcessMoveHorizontalInput(const FInputActionValue& InputValue)
{
	InputData.HorizontalMoveInput = InputValue.Get<float>();
}

void AShootingRangeCharacter::ResetMoveHorizontalInput(const FInputActionValue& InputValue)
{
	InputData.HorizontalMoveInput = 0.0f;
}

void AShootingRangeCharacter::ProcessLookVerticalInput(const FInputActionValue& InputValue)
{
	InputData.VerticalLookInput = InputValue.Get<float>();
}

void AShootingRangeCharacter::ResetLookVerticalInput(const FInputActionValue& InputValue)
{
	InputData.VerticalLookInput = 0.0f;
}

void AShootingRangeCharacter::ProcessLookHorizontalInput(const FInputActionValue& InputValue)
{
	InputData.HorizontalLookInput = InputValue.Get<float>();
}

void AShootingRangeCharacter::ResetLookHorizontalInput(const FInputActionValue& InputValue)
{
	InputData.HorizontalLookInput = 0.0f;
}

void AShootingRangeCharacter::ProcessJumpInput(const FInputActionValue& InputValue)
{
	Jump();
}

void AShootingRangeCharacter::ProcessShootInput(const FInputActionValue& InputValue)
{
#if UE_BUILD_DEBUG || UE_EDITOR
	PRINT_TEXT("Shoot", FColor::Red)
#endif
}
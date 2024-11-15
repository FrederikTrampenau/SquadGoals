// Copyright Frederik Trampenau All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "SquadGoals/Data/Input/FFirstPersonInputData.h"
#include "ShootingRangeCharacter.generated.h"

struct FInputActionValue;
struct FFirstPersonInputData;
class UFirstPersonCharacterInputConfig;
class UInputMappingContext;

UCLASS()
class SQUADGOALS_API AShootingRangeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AShootingRangeCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	FFirstPersonInputData InputData;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> InputMapping;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UFirstPersonCharacterInputConfig> InputActions;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveWithInput();
	void ProcessMoveVerticalInput(const FInputActionValue& InputValue);
	void ResetMoveVerticalInput(const FInputActionValue& InputValue);
	void ProcessMoveHorizontalInput(const FInputActionValue& InputValue);
	void ResetMoveHorizontalInput(const FInputActionValue& InputValue);
	void ProcessLookVerticalInput(const FInputActionValue& InputValue);
	void ResetLookVerticalInput(const FInputActionValue& InputValue);
	void ProcessLookHorizontalInput(const FInputActionValue& InputValue);
	void ResetLookHorizontalInput(const FInputActionValue& InputValue);
	void ProcessJumpInput(const FInputActionValue& InputValue);
	void ProcessShootInput(const FInputActionValue& InputValue);
};

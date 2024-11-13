#pragma once
#include "CoreMinimal.h"
#include "FFirstPersonInputData.generated.h"

USTRUCT(BlueprintType)
struct FFirstPersonInputData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HorizontalMoveInput;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VerticalMoveInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HorizontalLookInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VerticalLookInput;
};
// Copyright Frederik Trampenau All Rights Reserved.


#include "ShootingRangeCharacter.h"


// Sets default values
AShootingRangeCharacter::AShootingRangeCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AShootingRangeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShootingRangeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AShootingRangeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


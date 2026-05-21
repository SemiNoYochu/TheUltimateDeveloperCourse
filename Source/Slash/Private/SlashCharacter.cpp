// Fill out your copyright notice in the Description page of Project Settings.


#include "SlashCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


ASlashCharacter::ASlashCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASlashCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(SlashContext, 0 );
		}
	}
	
}

void ASlashCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	FVector Forward = GetActorForwardVector();
	AddMovementInput(Forward, MovementVector.Y);
	FVector Right = GetActorRightVector();
	AddMovementInput(Right, MovementVector.X);
}

void ASlashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASlashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent =
		CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(
			MovementAction, 
			ETriggerEvent::Triggered, 
			this, 
			&ASlashCharacter::Move);
	}
}


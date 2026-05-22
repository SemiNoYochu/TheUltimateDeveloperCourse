// Fill out your copyright notice in the Description page of Project Settings.


#include "SlashCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


ASlashCharacter::ASlashCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 450.0f, 0.0f);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUsePawnControlRotation = true;
	
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArm);
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
	if (GetController())
	{
		const FVector2D MovementVector = Value.Get<FVector2D>();
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotator(0.f, ControlRotation.Yaw, 0.f);
		
		const FVector Forward = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);
		AddMovementInput(Forward, MovementVector.Y);
		const FVector Right = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);
		AddMovementInput(Right, MovementVector.X);
	}
}

void ASlashCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	AddControllerPitchInput(LookAxisVector.Y);
	AddControllerYawInput(LookAxisVector.X);
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
		
		EnhancedInputComponent->BindAction(
			LookAction, 
			ETriggerEvent::Triggered, 
			this, 
			&ASlashCharacter::Look);
	}
}


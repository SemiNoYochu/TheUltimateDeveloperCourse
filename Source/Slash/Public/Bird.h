// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Bird.generated.h"

// forward declaration(Top-Level Forward Declaration)
class UCapsuleComponent;
class USkeletalMeshComponent;

UCLASS()
class SLASH_API ABird : public APawn
{
	GENERATED_BODY()

public:
	ABird();
	
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;
private:
	// forward declaration(Inline Forward Declaration)
	// class UCapsuleComponent* Capsule;
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;
	
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* BirdMesh;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Slash/DebugMacros.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	SetRootComponent(ItemMesh);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

#pragma region DrawDebug Variable Settings
	// UWorld* World = GetWorld();
	// SetActorLocation(FVector(0.f, 0.f, 200.f));
	// SetActorRotation(FRotator(0.f, 45.f, 0.f));
	// FVector Location = GetActorLocation();
	// FVector Forward = GetActorForwardVector();
	// FString ActorName = GetName();
	// FString Message = FString::Printf(TEXT("Actor Name: %s"), *ActorName);
#pragma endregion
#pragma region DrawDebug with MACRO
	// DRAW_SPHERE(Location)
	// DRAW_LINE(Location, Location + Forward * 100.f)
	// DRAW_POINT(Location + Forward * 100.f)
	// DRAW_VECTOR(Location, Location + Forward * 100.f)
	// DRAW_NEW_SPHERE(Location, FColor::Cyan)
	// DRAW_COORDINATE_SYSTEM(Location, GetActorRotation())
	// DRAW_STRING(Location, Message)
#pragma endregion
#pragma region Template with int32 and float
	// int32 AvgInt = Avg<int32>(1, 2);
	// UE_LOG(LogTemp, Warning, TEXT("(%s)Avg of 1 and 2: %d"), *GetName(),AvgInt)
	//
	// float AvgFloat = Avg<float>(3.45, 7.86);
	// if (GEngine)
	// {
	// 	GEngine->AddOnScreenDebugMessage(0, 60.f, FColor::Cyan, FString::Printf(TEXT("(%s)Avg of 3.45 and 7.89: %f"), *GetName(), AvgFloat));
	// }
#pragma endregion
}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

template <typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}

#pragma region UE_LOG & AddOnScreenDebugMessage
	// UE_LOG(LogTemp, Warning, TEXT("Begin Play!"));
	//
	// if (GEngine)
	// {
	// 	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Item OnScreen Message!"));
	// }
#pragma endregion
#pragma region DrawDebugSphere
	// Actor Class의 BeginPlay() fucntion이 Call 되었다는 것은
	// 해당 Actor 객체가 Level에 Spawnd 되었다는 얘기이므로 체크하지 논리상 체크하지 않아도 되지만,
	// Unreal Engine의 Code Convention에 의거하여 체크합니다.
	// if (World)
	// {
	// 	DrawDebugSphere(
	// 		World, 
	// 		Location, 
	// 		30, 
	// 		24, 
	// 		FColor::Cyan, 
	// 		false, 
	// 		60.f,
	// 		0,
	// 		2);
	// }
#pragma endregion
#pragma region DrawDebugLine
	// if (World)
	// {
	// 	
	// 	DrawDebugLine(
	// 		World, 
	// 		Location, 
	// 		Location + Forward * 100.f, 
	// 		FColor::Red, 
	// 		true, 
	// 		-1.f, 
	// 		0, 
	// 		1.f);
	// }
#pragma endregion
#pragma region DrawDebugPoint
	// if (World)
	// {
	// 	DrawDebugPoint(
	// 		World, 
	// 		Location + Forward * 100.f, 
	// 		30.f, 
	// 		FColor::Red, 
	// 		true);
	// }
#pragma endregion

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	RunningTime += DeltaTime;
	
#pragma region Template with FVector
	// FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	// DRAW_POINT_SINGLE_FRAME(AvgVector);
#pragma endregion 
#pragma region Movement
	// Movement Rate in units of cm/s
	// float MovementRate = 50.f;
	// float RotationRate = 25.f;
	
	// MovementRate * DeltaTime: (cm/s) * (s/frame) = (cm/frame)
	// AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	// AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
#pragma endregion
#pragma region Sin with C++
	// float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	// AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));	// period = 2pi/K
#pragma endregion
#pragma region UE_LOG & AddOnScreenDebugMessage
	// UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);
	//
	// if (GEngine)
	// {
	// 	FString MessageDeltaTime = FString::Printf(TEXT("DeltaTime: %f"), DeltaTime);
	// 	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, MessageDeltaTime);
	// 	
	// 	FString ObjectName = GetName();
	// 	FString MessageObjectName = FString::Printf(TEXT("ObjectName: %s"), *ObjectName);
	// 	GEngine->AddOnScreenDebugMessage(2, 60.f, FColor::Magenta, MessageObjectName);
	// 	
	// 	GEngine->AddOnScreenDebugMessage(3, 60.f, FColor::Blue, (TEXT("Name: %s"), *ObjectName));
	// 	
	// 	UE_LOG(LogTemp, Warning, TEXT("ObjectName: %s"), *ObjectName);
	// }
#pragma endregion
}


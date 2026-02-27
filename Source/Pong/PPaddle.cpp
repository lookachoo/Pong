// Fill out your copyright notice in the Description page of Project Settings.


#include "PPaddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
APPaddle::APPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>("PaddleMesh");
	RootComponent = PaddleMesh;

	MoveComp = CreateDefaultSubobject<UFloatingPawnMovement>("MoveComp");


}

// Called when the game starts or when spawned
void APPaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Loc = GetActorLocation();
	Loc.X = FMath::Clamp(Loc.X, MinX, MaxX);
	SetActorLocation(Loc);
}

// Called to bind functionality to input
void APPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!InputComp || !Input_MoveVertical) return;

	InputComp->BindAction(Input_MoveVertical, ETriggerEvent::Triggered, this, &APPaddle::MoveVertical);
	InputComp->BindAction(Input_MoveVertical, ETriggerEvent::Completed, this, &APPaddle::MoveVertical);
}

void APPaddle::MoveVertical(const FInputActionValue& Value)
{
	const float MoveValue = Value.Get<float>();

	AddMovementInput(FVector(1, 0, 0), MoveValue * PaddleSpeed);


}

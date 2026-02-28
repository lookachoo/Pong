// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "PPaddle.generated.h"

class UFloatingPawnMovement;
class UStaticMeshComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class PONG_API APPaddle : public APawn
{
	GENERATED_BODY()


public:
	// Sets default values for this pawn's properties
	APPaddle();


//  UProperty Setup
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	UPROPERTY(EditAnywhere, Category="Bounds")
	float MinX = -3000.f;

	UPROPERTY(EditAnywhere, Category="Bounds")
	float MaxX = 3000.f;

	// Input Variables
	UPROPERTY(EditAnywhere, Category="Input")
	float PaddleSpeed = 1;


	// Create Paddle Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* PaddleMesh;

public:
	UPROPERTY(EditAnywhere)
	UFloatingPawnMovement* MoveComp;

	
protected:
		// Set up input Paddle input
	//UPROPERTY(EditAnywhere, Category="Input")
	//UInputMappingContext* DefaultInputMapping;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* Input_MoveVertical = nullptr;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


//  Function Declarations

	
	UFUNCTION(BlueprintCallable)
	void MoveVertical(const FInputActionValue& Value);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

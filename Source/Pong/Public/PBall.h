// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
#include "PBall.generated.h"

class UStaticMeshComponent;
class APPaddle;
class UAudioComponent;

UCLASS()
class PONG_API APBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* BallMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* BallCollision;

	UPROPERTY(EditAnywhere)
	UAudioComponent* BounceSound;


	UPROPERTY(EditAnywhere, Category = "Defaults")
	float DefaultSpeed = 1500.f;

	UPROPERTY(EditAnywhere, Category="Defaults")
	bool HorizontalMovement = false;

	FVector Velocity;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PBall.generated.h"

class UStaticMeshComponent;

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

	UStaticMeshComponent* BallMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "PBall.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APBall::APBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>("BallMesh");

}

// Called when the game starts or when spawned
void APBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


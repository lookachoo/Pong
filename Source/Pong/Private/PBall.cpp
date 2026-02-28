// Fill out your copyright notice in the Description page of Project Settings.

#include "PBall.h"
#include "Components/StaticMeshComponent.h"
#include "../PPaddle.h"

// Sets default values
APBall::APBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>("BallMesh");
	RootComponent = BallMesh;

	BallCollision = CreateDefaultSubobject <UBoxComponent>("BallCollision");
	BallCollision->SetupAttachment(BallMesh);

	Velocity = FVector(0, 1, 0) * DefaultSpeed; // start moving right

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
	
	FHitResult Hit;
	AddActorWorldOffset(Velocity * DeltaTime, true, &Hit);
	if (Hit.bBlockingHit)
	{
		APPaddle* HitPaddle = Cast<APPaddle>(Hit.GetActor());
		if (HitPaddle)
		{
			const float PaddleX = HitPaddle->GetActorLocation().X;
			const float BallX = GetActorLocation().X;

			// -1..1 based on where ball hit relative to paddle center
			const float HalfHeight = 250.f; // set to your paddle half-size (or read from bounds)
			float Offset = (BallX - PaddleX) / HalfHeight;
			Offset = FMath::Clamp(Offset, -1.f, 1.f);

			// Convert offset to bounce angle, e.g. max 60 degrees
			const float MaxAngleDeg = 60.f;
			const float AngleRad = FMath::DegreesToRadians(Offset * MaxAngleDeg);

			// Decide which way the ball should go (left or right) after hit:
			const float DirY = (Velocity.Y >= 0.f) ? -1.f : 1.f; // flip Y direction

			// Build new direction from angle
			FVector NewDir;
			NewDir.X = FMath::Sin(AngleRad);
			NewDir.Y = DirY * FMath::Cos(AngleRad);
			NewDir.Z = 0.f;

			float Speed = DefaultSpeed;
			float PaddleSpeed = HitPaddle->GetVelocity().Size();
			Speed = PaddleSpeed + Speed;

			Velocity = NewDir.GetSafeNormal() * Speed;
		}
		else 
		{
			const FVector N = Hit.ImpactNormal.GetSafeNormal();
			Velocity = Velocity.MirrorByVector(N);
		}
	}
}
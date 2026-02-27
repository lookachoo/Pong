// Fill out your copyright notice in the Description page of Project Settings.


#include "PPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

void APPlayerController::BeginPlay()
{
	Super::BeginPlay();

    if (!IsLocalController())
        return;

    // Delay one frame / short time to let LocalPlayer initialize
    GetWorldTimerManager().SetTimerForNextTick(this, &APPlayerController::SetupInputContexts);

}

void APPlayerController::SetupInputContexts()
{
    UE_LOG(LogTemp, Warning, TEXT("BeginPlay: PC=%s Class=%s IsLocal=%d"),
        *GetName(),
        *GetClass()->GetName(),
        IsLocalController());

    ULocalPlayer* LP = GetLocalPlayer();
    if (!LP) return;

    UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    if (!Subsystem) return;

    const int32 Id = LP->GetControllerId();
    const int32 PlayerIndex = LP->GetLocalPlayerIndex();
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,
            5.f,
            FColor::Green,
            FString::Printf(TEXT("PlayerIndex = %d"), PlayerIndex)
        );
    }

    // Dont clear unless you really want to wipe everything:
    // Subsystem->ClearAllMappings();

    if (PlayerIndex == 0)
    {
        Subsystem->AddMappingContext(IMC_Player1, 0);
    }
    else if (PlayerIndex == 1)
    {
        Subsystem->AddMappingContext(IMC_Player2, 0);
    }
}
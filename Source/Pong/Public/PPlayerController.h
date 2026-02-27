// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class PONG_API APPlayerController : public APlayerController
{
	GENERATED_BODY()


protected:
    virtual void BeginPlay() override;

    void SetupInputContexts();

public:
    // Assign these in the BP child or defaults
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input")
    UInputMappingContext* IMC_Player1 = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input")
    UInputMappingContext* IMC_Player2 = nullptr;

};
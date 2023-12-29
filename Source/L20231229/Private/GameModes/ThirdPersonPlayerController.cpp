// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/ThirdPersonPlayerController.h"
#include "EnhancedInputSubsystems.h"

void AThirdPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* EnhancedSubsystem = ULocalPlayer::GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	EnhancedSubsystem->AddMappingContext(InputMappingContext, 0);
}

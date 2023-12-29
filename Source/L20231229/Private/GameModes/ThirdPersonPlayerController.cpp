// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/ThirdPersonPlayerController.h"
#include "EnhancedInputSubsystems.h"

void AThirdPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitializeEnhancedInputLocalPlayerSubsystem();
}

bool AThirdPersonPlayerController::InitializeEnhancedInputLocalPlayerSubsystem() const
{
	UEnhancedInputLocalPlayerSubsystem* EnhancedSubsystem = ULocalPlayer::GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (IsValid(EnhancedSubsystem))
	{
		EnhancedSubsystem->AddMappingContext(InputMappingContext, 0);
		return true;
	}
	return false;
}

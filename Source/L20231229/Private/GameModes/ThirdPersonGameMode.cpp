// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/ThirdPersonGameMode.h"

#include "GameModes/ThirdPersonCharacter.h"
#include "GameModes/ThirdPersonPlayerController.h"

AThirdPersonGameMode::AThirdPersonGameMode()
{
	PlayerControllerClass = AThirdPersonPlayerController::StaticClass();
	DefaultPawnClass = AThirdPersonCharacter::StaticClass();
}

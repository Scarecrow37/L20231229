// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/ThirdPersonCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AThirdPersonCharacter::AThirdPersonCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
}

// Called when the game starts or when spawned
void AThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AThirdPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
		IsValid(EnhancedInputComponent))
	{
		if (IsValid(MoveAction))
		{
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this,
			                                   &AThirdPersonCharacter::MoveActionTriggered);
		}
		if (IsValid(JumpAction))
		{
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this,
			                                   &AThirdPersonCharacter::JumpActionStarted);
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this,
			                                   &AThirdPersonCharacter::JumpActionCompleted);
		}
		if (IsValid(LookAction))
		{
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this,
			                                   &AThirdPersonCharacter::LookActionTriggered);
		}
	}
}

void AThirdPersonCharacter::MoveActionTriggered(const FInputActionValue& Value)
{
	const FVector2d Vector2dValue = Value.Get<FVector2d>();
	const FRotator ControlRotation = GetControlRotation();
	const FRotator CameraRotation(0, ControlRotation.Yaw, 0);
	const FVector ForwardVector = UKismetMathLibrary::GetForwardVector(CameraRotation);
	const FVector RightVector = UKismetMathLibrary::GetRightVector(CameraRotation);
	AddMovementInput(ForwardVector, Vector2dValue.Y);
	AddMovementInput(RightVector, Vector2dValue.X);
}

void AThirdPersonCharacter::JumpActionStarted(const FInputActionValue& Value)
{
	Jump();
}

void AThirdPersonCharacter::JumpActionCompleted(const FInputActionValue& Value)
{
	StopJumping();
}

void AThirdPersonCharacter::LookActionTriggered(const FInputActionValue& Value)
{
	const FVector2d Vector2dValue = Value.Get<FVector2D>();
	AddControllerYawInput(Vector2dValue.X);
	AddControllerPitchInput(Vector2dValue.Y);
}

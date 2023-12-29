// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/ThirdPersonAnimBlueprint.h"

#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

UThirdPersonAnimBlueprint::UThirdPersonAnimBlueprint(): GroundSpeed(0.0f), IsFalling(false), IsJumping(false),
                                                        ShouldMove(false), ShowingAnimationJumpSpeed(100.0f), HidingAnimationMovementSpeed(3.0f)
{
}

void UThirdPersonAnimBlueprint::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (const APawn* Pawn = TryGetPawnOwner(); IsValid(Pawn))
	{
		Velocity = Pawn->GetVelocity();
		Acceleration = Velocity - PreviousVelocity;
		PreviousVelocity = Velocity;
		GroundSpeed = Velocity.Size2D();
		if (const ACharacter* Character = Cast<ACharacter>(Pawn); IsValid(Character))
		{
			const UPawnMovementComponent* Movement = Character->GetMovementComponent();
			IsFalling = Movement->IsFalling();
			IsJumping = IsFalling && Velocity.Z > ShowingAnimationJumpSpeed;
			ShouldMove = Acceleration != FVector::Zero() && GroundSpeed > HidingAnimationMovementSpeed; 
		}
	}
}

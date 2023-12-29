// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ThirdPersonAnimBlueprint.generated.h"

/**
 * 
 */
UCLASS()
class L20231229_API UThirdPersonAnimBlueprint : public UAnimInstance
{
	GENERATED_BODY()

public:
	UThirdPersonAnimBlueprint();

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	FVector Velocity;
	FVector PreviousVelocity;
	FVector Acceleration;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float GroundSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	bool IsFalling;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	bool IsJumping;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	bool ShouldMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float ShowingAnimationJumpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float HidingAnimationMovementSpeed;
};

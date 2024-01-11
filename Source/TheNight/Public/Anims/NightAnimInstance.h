// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "NightAnimInstance.generated.h"

/**
 * 
 */

class ACharacter;

UCLASS()
class THENIGHT_API UNightAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UNightAnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	virtual void NativeBeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	FVector Velocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Owner")
	ACharacter* OwningCharacter;
	
};

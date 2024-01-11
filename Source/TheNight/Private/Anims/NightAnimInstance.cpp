// Fill out your copyright notice in the Description page of Project Settings.


#include "Anims/NightAnimInstance.h"

#include "GameFramework/Character.h"

UNightAnimInstance::UNightAnimInstance()
{
}


void UNightAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwningCharacter = Cast<ACharacter>(TryGetPawnOwner());
}


void UNightAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(!OwningCharacter) return;

	Velocity = OwningCharacter->GetVelocity();
}


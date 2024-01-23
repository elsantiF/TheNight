// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THENIGHT_API IInteractInterface
{
	GENERATED_BODY()

public:
	// Used to determine if you can interact with the object
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	bool CanInteract();

	// Used to warn the object that something wants to interact with it
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void StartFocus();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")	
	void EndFocus();

	// Used to interact with the object
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void Interact(AActor* OriginActor);
};

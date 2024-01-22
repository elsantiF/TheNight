// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NightAIController.generated.h"

/**
 * 
 */
UCLASS()
class THENIGHT_API ANightAIController : public AAIController
{
	GENERATED_BODY()

public:
	ANightAIController();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BT;
	
};

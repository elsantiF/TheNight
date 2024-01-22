// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/NightAIController.h"

ANightAIController::ANightAIController()
{
}

void ANightAIController::BeginPlay()
{
	Super::BeginPlay();

	if(!BT) return;
	
	RunBehaviorTree(BT);
}

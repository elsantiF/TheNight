// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NightAICharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
ANightAICharacter::ANightAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComp");

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void ANightAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
	PawnSensingComp->OnSeePawn.AddDynamic(this, &ANightAICharacter::OnPawnSeen);
}

AActor* ANightAICharacter::GetTargetActor() const
{
	AAIController* AIC = Cast<AAIController>(GetController());
	
	if (!AIC) return nullptr;
	
	return Cast<AActor>(AIC->GetBlackboardComponent()->GetValueAsObject("Target"));
}

void ANightAICharacter::SetTargetActor(AActor* NewTarget)
{
	AAIController* AIC = Cast<AAIController>(GetController());
	
	if (!AIC) return;
	
	AIC->GetBlackboardComponent()->SetValueAsObject("Target", NewTarget);
}

void ANightAICharacter::OnPawnSeen(APawn* Pawn)
{
	if (GetTargetActor() == Pawn) return;
	
	SetTargetActor(Pawn);
}





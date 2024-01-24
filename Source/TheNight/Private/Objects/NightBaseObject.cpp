// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/NightBaseObject.h"

#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"

// Sets default values
ANightBaseObject::ANightBaseObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(RootComponent);

	WidgetText = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetText"));
	WidgetText->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ANightBaseObject::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ANightBaseObject::CanInteract_Implementation()
{
	return true;
}

void ANightBaseObject::StartFocus_Implementation()
{
	WidgetText->SetVisibility(true);
}

void ANightBaseObject::EndFocus_Implementation()
{
	WidgetText->SetVisibility(false);
}

void ANightBaseObject::Interact_Implementation(AActor* OriginActor)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, GetActorLocation(), GetActorRotation(), SpawnParams);
}


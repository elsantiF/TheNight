// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/NightBaseObject.h"

#include "Components/WidgetComponent.h"

// Sets default values
ANightBaseObject::ANightBaseObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);

	WidgetText = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetText"));
	WidgetText->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ANightBaseObject::BeginPlay()
{
	Super::BeginPlay();
	
}
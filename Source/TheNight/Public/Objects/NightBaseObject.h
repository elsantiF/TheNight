// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/InteractInterface.h"
#include "NightBaseObject.generated.h"

class UBoxComponent;
class UWidgetComponent;

UCLASS()
class THENIGHT_API ANightBaseObject : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANightBaseObject();

	virtual bool CanInteract_Implementation() override;
	virtual void StartFocus_Implementation() override;
	virtual void EndFocus_Implementation() override;
	virtual void Interact_Implementation(AActor* OriginActor) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Componnets")
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(EditDefaultsOnly, Category = "Componnets")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "Componnets")
	TObjectPtr<UBoxComponent> BoxComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Componnets")
	TObjectPtr<UWidgetComponent> WidgetText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn")
	TSubclassOf<AActor> ActorToSpawn;
};

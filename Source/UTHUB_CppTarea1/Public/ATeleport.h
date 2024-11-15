// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATeleport.generated.h"

class UBoxComponent;
class UParticleEmitter;

UCLASS()
class UTHUB_CPPTAREA1_API AATeleport : public AActor
{
	GENERATED_BODY()

public:

	// Sets default values for this actor's properties
	AATeleport();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	USceneComponent* Root;
	bool bActiveTeleport;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
		
	UPROPERTY(EditAnywhere, Category="Teleport")
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, Category="Teleport")
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	TSubclassOf<ACharacter> TeleportActorClass;

	UPROPERTY(EditInstanceOnly, Category="Teleport")
	AATeleport* BindedTeleportActor;

	UFUNCTION()
	void Teleport(ACharacter* Character2Teleport) const;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	USoundBase* TeleportSound;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	UParticleSystem* TeleportEmitter;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributesManagerComponent.generated.h"


class UPAttribute;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UTHUB_CPPTAREA1_API UAttributesManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAttributesManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category="Attributes")
	bool CheckAttribute(const FName AttrName);
	
	UFUNCTION(BlueprintCallable, Category="Attributes")
	void EditAttribute(const FName& AttrName, UPAttribute* NewValue);
	
	UFUNCTION(BlueprintCallable, Category="Attributes")
	void AddAttribute(const FName& AttrName, UPAttribute* NewValue);

	UFUNCTION(BlueprintCallable, Category="Attributes")
	void RemoveAttribute(const FName AttrName);

	UFUNCTION(BlueprintCallable, Category="Attributes")
	UPAttribute* GetAttribute(const FName AttrName);
	
	UPROPERTY(EditAnywhere)
	TMap<FName, UPAttribute*> AttributesMap;
	
};

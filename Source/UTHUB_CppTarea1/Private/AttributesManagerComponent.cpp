// Fill out your copyright notice in the Description page of Project Settings.


#include "UTHUB_CppTarea1/Public/AttributesManagerComponent.h"


// Sets default values for this component's properties
UAttributesManagerComponent::UAttributesManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAttributesManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAttributesManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
bool UAttributesManagerComponent::CheckAttribute(const FName AttrName)
{
	if (AttributesMap.FindChecked(AttrName))
		return true;

	return false;
}

void UAttributesManagerComponent::EditAttribute(const FName& AttrName, UPAttribute* NewValue)
{
	AttributesMap.Emplace(AttrName, NewValue);
}

void UAttributesManagerComponent::AddAttribute(const FName& AttrName, UPAttribute* NewValue)
{
	AttributesMap.FindOrAdd(AttrName, NewValue);
}

void UAttributesManagerComponent::RemoveAttribute(const FName AttrName)
{
	AttributesMap.Remove(AttrName);
}

UPAttribute* UAttributesManagerComponent::GetAttribute(const FName AttrName)
{
	return (AttributesMap.FindChecked(AttrName));
}

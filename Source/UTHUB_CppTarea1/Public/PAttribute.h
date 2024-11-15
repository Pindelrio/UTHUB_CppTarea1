// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PAttribute.generated.h"

/**
 * 
 */
UCLASS()
class UTHUB_CPPTAREA1_API UPAttribute : public UObject
{
	GENERATED_BODY()

	float Value;
	public:
	float GetValue() const;
	void SetValue(const float _value);
};

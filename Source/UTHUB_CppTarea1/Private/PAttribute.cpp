// Fill out your copyright notice in the Description page of Project Settings.


#include "PAttribute.h"

float UPAttribute::GetValue() const
{
	return Value;
}

void UPAttribute::SetValue(const float _value)
{
	Value = _value;
}

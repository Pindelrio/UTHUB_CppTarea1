// Copyright Epic Games, Inc. All Rights Reserved.

#include "UTHUB_CppTarea1GameMode.h"
#include "UTHUB_CppTarea1Character.h"
#include "UObject/ConstructorHelpers.h"

AUTHUB_CppTarea1GameMode::AUTHUB_CppTarea1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

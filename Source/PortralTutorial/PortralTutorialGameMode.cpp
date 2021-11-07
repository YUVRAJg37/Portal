// Copyright Epic Games, Inc. All Rights Reserved.

#include "PortralTutorialGameMode.h"
#include "PortralTutorialCharacter.h"
#include "UObject/ConstructorHelpers.h"

APortralTutorialGameMode::APortralTutorialGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

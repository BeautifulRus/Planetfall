// Copyright Epic Games, Inc. All Rights Reserved.


#include "PlanetfallGameModeBase.h"

#include "PlanetfallPawn.h"
#include "PlanetfallPlayerController.h"

APlanetfallGameModeBase :: APlanetfallGameModeBase()
{
	PlayerControllerClass=APlanetfallPlayerController::StaticClass();
	DefaultPawnClass=APlanetfallPawn::StaticClass();
	
}

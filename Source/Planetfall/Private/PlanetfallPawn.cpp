// Fill out your copyright notice in the Description page of Project Settings.
#include "PlanetfallPawn.h"

#include <Windows.Graphics.Display.h>

#include "iostream"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
APlanetfallPawn::APlanetfallPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent=CreateDefaultSubobject<UStaticMeshComponent>("DefaultSceneRootComponent");
	SpringArmComponent=CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->TargetArmLength=700.0f;
	SpringArmComponent->SetupAttachment(SceneComponent);
	CameraComponent=CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
	bUseControllerRotationYaw=true;
	SpringArmComponent->SetRelativeRotation(FRotator(-70,0,0));
	SpringArmComponent->bDoCollisionTest=false;
	
}









inline float CameraMovementPreparing(const FVector2d ViewportSize, const float FMousePositionX, const float FMousePositionY, float &MoveLeft, float &MoveRight, float & MoveUpward, float &MoveDown)
{
	
	double LimitByX = FMousePositionX / ViewportSize.X;
	double LimitByY = FMousePositionY / ViewportSize.Y;
	UE_LOG(LogTemp, Warning, TEXT("LimitByXY, %f %f"), LimitByX, LimitByY);
	
	if (LimitByX<=0.04f)
	{
		MoveLeft = 0.25f;
		if (LimitByX<=0.03f)
		{
			MoveLeft = 0.5f;
		
			if (LimitByX<=0.02f)
			{
				MoveLeft = 0.75f;
			
				if (LimitByX<=0.01f)
				{
					MoveLeft = 1.0f;
				}
			}	
		}
	}; //Проверка на местонахождение курсора, и скейл значения от близости курсора к ЛЕВОМУ краю экрана
	if (LimitByX>=0.96f)
	{
		MoveRight = 0.25f;
		if (LimitByX>=0.97f)
		{
			MoveRight = 0.5f;
		
			if (LimitByX>=0.98f)
			{
				MoveRight = 0.75f;
			
				if (LimitByX>=0.99f)
				{
					MoveRight = 1.0f;
				}
			}
		}
	}; //Проверка на местонахождение курсора, и скейл значения от близости курсора к ПРАВОМУ краю экрана
	if (LimitByY<=0.04f)
	{
		MoveDown = 0.25f;
		if (LimitByY>=0.03f)
		{
			MoveDown = 0.5f;
			if (LimitByY>=0.02f)
			{
				MoveDown = 0.75f;
				if (LimitByY>=0.01f)
				{
					MoveDown=1.0f;
				}
			}
		}
	}; //Проверка на местонахождение курсора, и скейл значения от близости курсора к ВЕРХНЕМУ краю экрана
	if (LimitByY>=0.96f)
	{
		MoveUpward=0.25f;
		if (LimitByY<=0.97f)
		{
			MoveUpward=0.5f;
			if (LimitByY<=0.98f)
			{
				MoveUpward=0.75f;
				if (LimitByY<=0.99f)
				{
					MoveUpward=1.0f;
				}
			}
		}
	}; //Проверка на местонахождение курсора, и скейл значения от близости курсора к НИЖНЕМУ краю экрана
	//ЛЕВО И НИЗ РАБОТАЮТ КАК НАДО
	
	return MoveLeft, MoveRight, MoveUpward, MoveDown;
}



/*
inline void CameraMove(float &MoveLeft, float &MoveRight, float &MoveUpward, float &MoveDown)
{
	if (MoveLeft>=0)
	{
		AddActorLocalOffset(FVector(0, -10*MoveLeft, 0), false, false);
	}
	if (MoveRight>=0)
	{
		AddActorLocalOffset(FVector(0,10*MoveRight,0), false, false);
	}
	if (MoveUpward>=0)
	{
		AddActorLocalOffset(FVector(10*MoveUpward,0,0), false, false);
	}
	if (MoveDown>=0)
	{
		AddActorLocalOffset(FVector(-10*MoveRight,0,0), false, false);
	}
}
*/

//*/







// Called when the game starts or when spawned
void APlanetfallPawn::BeginPlay()
{
	Super::BeginPlay();

	
	
}






// Called every frame
void APlanetfallPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PrimaryActorTick.bCanEverTick=true;

	




	ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());




	//FVector CameraRootComponentLocation = GetActorLocation();
	//UE_LOG(LogTemp, Warning, TEXT("CameraCoordinateXYZ, %f %f %f"), CameraRootComponentLocation.X, CameraRootComponentLocation.Y, CameraRootComponentLocation.Z);
	//UE_LOG(LogTemp, Warning, TEXT("ViewportSize, %f %f"), ViewportSize.X, ViewportSize.Y)
	MoveLeft=0; MoveRight=0; MoveUpward=0;	MoveDown=0;
	GameplayStatics->GetPlayerController(GetWorld(),0)->GetMousePosition(FMousePositionX, FMousePositionY);
	CameraMovementPreparing(ViewportSize, FMousePositionX, FMousePositionY, MoveLeft, MoveRight, MoveUpward, MoveDown);
	
	UE_LOG(LogTemp, Warning, TEXT("MousePositionXY, %f %f"), FMousePositionX, FMousePositionY);
	UE_LOG(LogTemp, Warning, TEXT("MoveLeft, %f"), MoveLeft);
	UE_LOG(LogTemp, Warning, TEXT("MoveRight, %f"), MoveRight);
	UE_LOG(LogTemp, Warning, TEXT("MoveUpward, %f"), MoveUpward);
	UE_LOG(LogTemp, Warning, TEXT("MoveDown, %f"), MoveDown);
	{
		if (MoveLeft>=0)
		{
			AddActorLocalOffset(FVector(0, -10*MoveLeft, 0), false, false);
		}
		if (MoveRight>=0)
		{
			AddActorLocalOffset(FVector(0,10*MoveRight,0), false, false);
		}
		if (MoveUpward>=0)
		{
			AddActorLocalOffset(FVector(-10*MoveUpward,0,0), false, false);
		}
		if (MoveDown>=0)
		{
			AddActorLocalOffset(FVector(10*MoveRight,0,0), false, false);
		}
	}



	
}





// Called to bind functionality to input
void APlanetfallPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


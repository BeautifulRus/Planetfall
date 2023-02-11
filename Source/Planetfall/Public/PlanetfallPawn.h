// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "PlanetfallPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UCameraComponent;


UCLASS()
class PLANETFALL_API APlanetfallPawn : public APawn
{
	GENERATED_BODY()








public:
	// Sets default values for this pawn's properties
	APlanetfallPawn();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Camera)
	UCameraComponent* CameraComponent;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Camera)
	USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category=Camera)
	USceneComponent* SceneComponent;
	
//	UPROPERTY()
	//APlayerController* PC;
	UPROPERTY()
	UGameplayStatics* GameplayStatics;

	UPROPERTY()
	FVector2D ViewportSize;
	
	
	


public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	

	





private:
	//UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category=Camera,meta=(ClampMin="0", ClampMax="100", AllowPrivateAccess=true))
	//float MoveSpeedCamera = 0.0f;
	UPROPERTY()
	float FMousePositionX= 0.0f, FMousePositionY=0.0f;

	UPROPERTY(meta=(ClampMin=0, ClampMax=1, AllowPrivateAccess))
	float MoveLeft=0, MoveRight=0, MoveUpward=0, MoveDown=0;
	
};

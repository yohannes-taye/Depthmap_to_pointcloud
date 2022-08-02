// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CineCameraActor.h"
#include "../../Plugins/PointCloudKit/Source/PointCloudEmitter/Public/PointCloudActor.h"
#include "GameFramework/Actor.h"
#include "CustomCamera.generated.h"

UCLASS()
class DEPTHPOINTCLOUD5_API ACustomCamera : public ACineCameraActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACustomCamera(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, Category="DebugProperties")
	AActor *projection;

	UPROPERTY(EditAnywhere, Category="DEbugProperties")
	APointCloudActor *PCActor;

	UPROPERTY(EditAnywhere, Category="DEbugProperties")
	float TresholdWidth = 1;

	UPROPERTY(EditAnywhere, Category="DEbugProperties")
	float TresholdHeight = 1; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float Distance = 0;
	float LastWidth = 0;
	float LastHeight = 0; 
};

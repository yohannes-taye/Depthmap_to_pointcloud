// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CineCameraActor.h"
#include "Math/Vector2D.h"
#include "Camera/CameraComponent.h"
#include "CinematicCamera/Public/CineCameraComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CameraFunctionLibrary.generated.h"
/**
 * 
 */
UCLASS()
class DEPTHPOINTCLOUD5_API UCameraFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public: 
	UFUNCTION(BlueprintCallable, Category="MyCategory")
	static float GetFrustumWidth(UCameraComponent* Camera, float Distance);
	UFUNCTION(BlueprintCallable, Category="MyCategory")
	static float GetFrustumHeight(UCameraComponent* Camera, float Distance, bool FixedAspectRatio);

	UFUNCTION(BlueprintCallable, Category="MyCategory")
	static float GetDistanceByFrustumWidth(UCameraComponent* Camera, float FrustumWidth);

	UFUNCTION(BlueprintCallable, Category="MyCategory")
	static float GetDistanceByFrustumHeight(UCameraComponent* Camera, float FrustumHeight, bool FixedAspectRatio);

	UFUNCTION(BlueprintCallable, Category="MyCategory")
	static float GetFieldOfViewByFrustumWidth(UCameraComponent* Camera, float Distance, float FrustumWidth);

	UFUNCTION(BlueprintCallable, Category="MyCategory")
	static float GetFieldOfViewByFrustumHeight(UCameraComponent* Camera, float Distance, float FrustumHeight,
	                                    bool FixedAspectRatio);

	UFUNCTION(BlueprintCallable, Category="MyCategory")
	static float GetAspectRatio(UCameraComponent* Camera, bool FixedAspectRatio);
};

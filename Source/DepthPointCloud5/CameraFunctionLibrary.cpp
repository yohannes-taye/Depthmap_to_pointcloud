// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraFunctionLibrary.h"

#include "CineCameraActor.h"
#include "Blueprint/WidgetLayoutLibrary.h"

// float UCameraFunctionLibrary::GetFrustumWidth(UCameraComponent* Camera, float Distance)
// {
// 	FMinimalViewInfo info;
// 	Camera->GetCameraView(0, info);
// 	const float FrustumAngle = info.FOV;
// 	const float HozHalfAngleInRadians = FMath::DegreesToRadians(FrustumAngle * 0.5f);
// 	return Distance * FMath::Tan(HozHalfAngleInRadians) * 2.0f; 
// }


float UCameraFunctionLibrary::GetFrustumWidth(UCameraComponent* Camera, float Distance)
{
	FMinimalViewInfo info;
	// CameraComponent->GetCameraView(0, info);
	Camera->GetCameraView(0, info);
	const float FrustumAngle = info.FOV;
	const float HozHalfAngleInRadians = FMath::DegreesToRadians(FrustumAngle * 0.5f);
	return Distance * FMath::Tan(HozHalfAngleInRadians) * 2.0f; 
}

float UCameraFunctionLibrary::GetFrustumHeight( UCameraComponent* Camera, float Distance, bool FixedAspectRatio/* = false*/ )
{
	const float AspectRatio = GetAspectRatio(Camera, FixedAspectRatio);
	return GetFrustumWidth(Camera, Distance) / AspectRatio;
}

float UCameraFunctionLibrary::GetDistanceByFrustumWidth( UCameraComponent* Camera, float FrustumWidth )
{
	FMinimalViewInfo info;
	Camera->GetCameraView(0, info);
	const float FrustumAngle = info.FOV;
	const float HozHalfAngleInRadians = FMath::DegreesToRadians(FrustumAngle * 0.5f);
	return FrustumWidth * 0.5f / FMath::Tan(HozHalfAngleInRadians);
}

float UCameraFunctionLibrary::GetDistanceByFrustumHeight( UCameraComponent* Camera, float FrustumHeight, bool FixedAspectRatio/* = false*/ )
{
	const float AspectRatio = GetAspectRatio(Camera, FixedAspectRatio);
	return GetDistanceByFrustumWidth( Camera, FrustumHeight*AspectRatio );
}

float UCameraFunctionLibrary::GetFieldOfViewByFrustumWidth( UCameraComponent* Camera, float Distance, float FrustumWidth )
{
	Distance = FMath::Abs(Distance);
	float Radians = 2.0f * FMath::Atan(FrustumWidth * 0.5f / Distance);
	return FMath::RadiansToDegrees(Radians);
}

float UCameraFunctionLibrary::GetFieldOfViewByFrustumHeight( UCameraComponent* Camera, float Distance, float FrustumHeight, bool FixedAspectRatio/* = false*/ )
{
	const float AspectRatio = GetAspectRatio(Camera, FixedAspectRatio);
	return GetFieldOfViewByFrustumWidth( Camera, Distance, FrustumHeight*AspectRatio );
}

float UCameraFunctionLibrary::GetAspectRatio( UCameraComponent* Camera, bool FixedAspectRatio/* = false*/ ) 
{
	float AspectRatio;
	if( FixedAspectRatio )
	{
		FMinimalViewInfo info;
		Camera->GetCameraView(0, info);
		AspectRatio = info.AspectRatio;
	}
	else
	{
		FVector2D Size = UWidgetLayoutLibrary::GetViewportSize(Camera->GetWorld());
		AspectRatio = Size.X/Size.Y;
	}
	return AspectRatio;
	// return 1; 
}

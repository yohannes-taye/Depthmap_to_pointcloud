// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomCamera.h"

#include "CameraFunctionLibrary.h"

DEFINE_LOG_CATEGORY_STATIC(LaliLog, Log, All); 
// Sets default values const FObjectInitializer& ObjectInitializer
ACustomCamera::ACustomCamera(const FObjectInitializer& ObjectInitializer):ACineCameraActor(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACustomCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// if(projection)
	// {
	// 	Distance = GetDistanceTo(projection); 
	// 	const float Width = UCameraFunctionLibrary::GetFrustumWidth(GetCameraComponent(), Distance);
	// 	const float Height = UCameraFunctionLibrary::GetFrustumHeight(GetCameraComponent(), Distance, true); 
	// 	projection->SetActorScale3D(FVector(Height / 100, Width / 100, 1)); 
	// 	// UE_LOG(LaliLog, Log, TEXT("Height: %f"), Height);	
	// }

	if(PCActor)
	{

		Distance = GetDistanceTo(PCActor);
		const float FrustumWidth = UCameraFunctionLibrary::GetFrustumWidth(GetCameraComponent(), Distance);
		const float FrustumHeight = UCameraFunctionLibrary::GetFrustumHeight(GetCameraComponent(), Distance, true);
		UPointCloudSystemComponent *PointCloudComponent = PCActor->GetPointCloudComponent();
		UPointCloudAnimationSetup *PCA = PointCloudComponent->GetPCA();
		TArray<FUserMaterialParameterScalar> ScalarMaterialParamters  = PCA->m_materialParametersScalar;
		ScalarMaterialParamters[2].parameter = FrustumWidth;
		ScalarMaterialParamters[3].parameter = FrustumHeight; 
		float Width = ScalarMaterialParamters[2].parameter * TresholdWidth;
		float Height = ScalarMaterialParamters[3].parameter * TresholdHeight;
		if ( LastWidth != Width || LastHeight != Height)
		{
			UE_LOG(LaliLog, Log, TEXT("Width: %f, Height: %f"), Width, Height);

			PointCloudComponent->UpdateWidthAndHeight(Width, Height); 
		}
		LastHeight = Height;
		LastWidth = Width;
		 
	}
	
	
}


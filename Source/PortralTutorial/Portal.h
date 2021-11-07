// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Portal.generated.h"

UCLASS()
class PORTRALTUTORIAL_API APortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBeginOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

private:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components, meta =(AllowPrivateAccess = "true"))
	UStaticMeshComponent* PortalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components, meta =(AllowPrivateAccess = "true"))
	UBoxComponent* PortalCollider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components, meta =(AllowPrivateAccess = "true"))
	USceneComponent* PortalExitLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components, meta =(AllowPrivateAccess = "true"))
	TSubclassOf<APortal> PortalClass;

	TArray<AActor*> PortalArray;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components, meta =(AllowPrivateAccess = "true"))
	int32 PortalIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components, meta =(AllowPrivateAccess = "true"))
	bool bEntrance;

public:

	FORCEINLINE int32 GetPortalIndex(){return PortalIndex;}
	FORCEINLINE USceneComponent* GetSceneComponent(){return PortalExitLocation;}

	
	
};



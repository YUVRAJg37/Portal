// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"

#include "PortralTutorialCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APortal::APortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PortalCollider = CreateDefaultSubobject<UBoxComponent>("Portal Collider");
	RootComponent = PortalCollider;
	
	PortalMesh = CreateDefaultSubobject<UStaticMeshComponent>("Portal Mesh");
	PortalMesh->SetupAttachment(PortalCollider);

	PortalExitLocation = CreateDefaultSubobject<USceneComponent>("Portal Exit");
	PortalExitLocation->SetupAttachment(PortalCollider);
	
}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();

	PortalCollider->OnComponentBeginOverlap.AddDynamic(this, &APortal::OnBeginOverLap);
	
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APortal::OnBeginOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APortralTutorialCharacter* PlayerCharacter = Cast<APortralTutorialCharacter>(OtherActor);
	if(PlayerCharacter)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), PortalClass, PortalArray);
		for(int32 i=0; i<PortalArray.Num(); i++)
		{
			APortal* Portal = Cast<APortal>(PortalArray[i]);
			if(Portal)
			{
				if(Portal->GetPortalIndex() == this->PortalIndex && this->bEntrance && !Portal->bEntrance)
				{
					PlayerCharacter->SetActorLocation(Portal->GetSceneComponent()->GetComponentLocation());
				}
				if((Portal->GetPortalIndex() == this->PortalIndex) && !this->bEntrance && Portal->bEntrance)
				{
					UE_LOG(LogTemp, Warning, TEXT("Working"));
					PlayerCharacter->SetActorLocation(Portal->GetSceneComponent()->GetComponentLocation());
				}
			}
		}
	}
}


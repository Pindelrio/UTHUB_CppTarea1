// Fill out your copyright notice in the Description page of Project Settings.


#include "ATeleport.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/MapErrors.h"
#include "Particles/ParticleEmitter.h"



// Sets default values
AATeleport::AATeleport()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(FName("BoxComponent"));
	BoxComponent->SetupAttachment(Root);
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(Root);
	bActiveTeleport = true;
}

// Called when the game starts or when spawned
void AATeleport::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AATeleport::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AATeleport::OnOverlapEnd);
}

// Called every frame
void AATeleport::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AATeleport::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(bActiveTeleport && BindedTeleportActor)
	{
		BindedTeleportActor->bActiveTeleport = false;
		ACharacter* Char2Teleport = Cast<ACharacter>(OtherActor); 
		Teleport(Char2Teleport);
	}
}

void AATeleport::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bActiveTeleport = true;
}

void AATeleport::Teleport(ACharacter* Character2Teleport) const
{
	if (Character2Teleport == nullptr)
		return;

	APlayerCameraManager* Camera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	Camera->StartCameraFade(1.f, 0.f, 1.f, FLinearColor::Black, true, true);
	
	Character2Teleport->TeleportTo(BindedTeleportActor->GetActorLocation(), Character2Teleport->GetActorRotation());
	if(TeleportEmitter)
		UGameplayStatics::SpawnEmitterAttached(TeleportEmitter,Root);

	if(TeleportSound)
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), TeleportSound, this->GetActorLocation());
}

void AATeleport::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(AATeleport, BindedTeleportActor))
	{
		if (BindedTeleportActor)
		{
			BindedTeleportActor->BindedTeleportActor = this;
		}
	}
}


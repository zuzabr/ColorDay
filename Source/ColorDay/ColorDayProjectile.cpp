// Copyright Epic Games, Inc. All Rights Reserved.

#include "ColorDayProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Components/DecalComponent.h"

#include "Actors/ColorInteractionInterface.h"
#include "Actors/ColorDayActor.h"

#include "ColorDayDebugHelper.h"

AColorDayProjectile::AColorDayProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(2.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AColorDayProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 5000.f;
	ProjectileMovement->MaxSpeed = 5000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 6.0f;
}

void AColorDayProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	//************************************Spawn Effects of Hit, need to be changed due to type of actor hit**************************
	const auto PaintEffect = ProjectileInfo.PaintSplatterEffect;
	if (PaintEffect && GetWorld())
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			GetWorld(),
			PaintEffect,
			Hit.ImpactPoint,
			Hit.ImpactNormal.Rotation()
		);
	}

	const auto PaintDecal = ProjectileInfo.PaintDecalMaterial;
	const auto DecalSize = ProjectileInfo.DecalSize;
	if (PaintDecal && GetWorld())
	{
		UDecalComponent* Decal = UGameplayStatics::SpawnDecalAtLocation(
			GetWorld(),
			PaintDecal,
			DecalSize,
			Hit.ImpactPoint,
			Hit.ImpactNormal.Rotation()
		);
		if (Decal)
		{
			Decal->SetLifeSpan(10.f); // Optional: Set decal lifetime
		}
	}



	const auto HitActor = OtherActor;
	const auto HittedComp = OtherComp;

	//*********************************** Send a logic to iteractive actor********************************************************
	if (auto InteractionInterface = Cast<IColorInteractionInterface>(HitActor))
	{
		InteractionInterface->TryToHitItem(ProjectileInfo.AmmoTag);
	}

	//*********************************** Add impulse if we hit a physics**************************************************			
	if ((HitActor != nullptr) && (HitActor != this) && (HittedComp != nullptr) && HittedComp->IsSimulatingPhysics())
	{
		HittedComp->AddImpulseAtLocation(GetVelocity() * 10.0f, GetActorLocation());

	}

	
	//*********************************** Send a logic to actor with physics material********************************************************
	if (HitActor->ActorHasTag(TEXT("Tag_Floor")))
	{
		Debug::Print(TEXT("Tag_Floor"));
	}

	Destroy();
}

void AColorDayProjectile::SpawnColorActor(const FHitResult& Hit)
{
	/*const auto ActorToSpawn = ProjectileInfo.ActorToSpawn;

	if (!ActorToSpawn || !GetWorld()) return;

	FTransform ActorSpawnTransform;
	ActorSpawnTransform.SetLocation(Hit.ImpactPoint);
	ActorSpawnTransform.SetRotation(Hit.ImpactNormal.ToOrientationQuat());
	ActorSpawnTransform.SetScale3D(FVector(1.0f));

	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;


	GetWorld()->SpawnActor<AColorDayActor>(ActorToSpawn, ActorSpawnTransform, ActorSpawnParams);*/
	
}

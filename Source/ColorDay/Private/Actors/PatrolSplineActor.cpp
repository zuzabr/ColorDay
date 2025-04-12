// ZuzabrGames All rights reserved 2024


#include "Actors/PatrolSplineActor.h"
#include "Components/SplineComponent.h"


APatrolSplineActor::APatrolSplineActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	RootComponent = SplineComponent;

}

FVector APatrolSplineActor::GetCurrentPointLocation() const
{
	if (!SplineComponent) return FVector::ZeroVector;
	
	return SplineComponent->GetLocationAtSplinePoint(CurrentPointIndex, ESplineCoordinateSpace::World);
	
}

int32 APatrolSplineActor::GetNumberOfPoints() const
{
	return SplineComponent ? SplineComponent->GetNumberOfSplinePoints() : 0;
}

void APatrolSplineActor::GoToNextPoint(bool bLoopedPath)
{
	if (bLoopedPath)
	{
		CurrentPointIndex = CurrentPointIndex + Direction;

		if (CurrentPointIndex == GetNumberOfPoints())
		{
			CurrentPointIndex = 0;
		}
		else if(CurrentPointIndex ==-1)
		{
			CurrentPointIndex = GetNumberOfPoints() - 1;
		}
	}

	else
	{
		CurrentPointIndex = CurrentPointIndex + Direction;
		
		if (CurrentPointIndex == GetNumberOfPoints()-1)
		{
			Direction = -1;
		}

		else if (CurrentPointIndex == 0)
		{
			Direction = 1;
		}
	}
}



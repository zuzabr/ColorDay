// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolSplineActor.generated.h"

class USplineComponent;

UCLASS()
class COLORDAY_API APatrolSplineActor : public AActor
{
	GENERATED_BODY()
	
public:	
	APatrolSplineActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spline")
	USplineComponent* SplineComponent;

	UFUNCTION(BlueprintCallable, Category = "Spline")
	FVector GetCurrentPointLocation() const;

	UFUNCTION(BlueprintCallable, Category = "Spline")
	int32 GetNumberOfPoints() const;

	void GoToNextPoint(bool bLoopedPath);


private:
	int32 CurrentPointIndex = 0;
	int32 Direction = 1;

};

// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColorDayActor.generated.h"

UCLASS()
class COLORDAY_API AColorDayActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColorDayActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};

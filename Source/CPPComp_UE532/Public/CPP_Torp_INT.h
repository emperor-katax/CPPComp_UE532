#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/TargetPoint.h" 
#include "CPP_Torp_INT.generated.h"

UCLASS()
class CPPCOMP_UE532_API ACPP_Torp_INT : public AActor{
	GENERATED_BODY()
	
public:	
	ACPP_Torp_INT();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Torp_INT Variables", meta = (ExposeOnSpawn = "true"))
	ATargetPoint* TargetPoint;
	//AActor* TargetPoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Torp_INT Variables", meta = (ExposeOnSpawn = "true"))
	float Speed = 500.f;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	bool Active = false;
	bool impact = false;
	FVector Target = FVector(FVector::ZeroVector);

	void Move();
	
	// temp vars
	FVector temp_01 = FVector(FVector::ZeroVector);
	float temp_02 = 0.f;
};

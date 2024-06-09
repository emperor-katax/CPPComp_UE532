#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/TargetPoint.h" 
#include "CPP_Torp_DEF.generated.h"

UCLASS()
class CPPCOMP_UE532_API ACPP_Torp_DEF : public AActor{
	GENERATED_BODY()
	
public:	
	ACPP_Torp_DEF();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Torp_DEF Variables", meta = (ExposeOnSpawn = "true"))
	ATargetPoint* TargetPoint;
	//AActor* TargetPoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Torp_DEF Variables", meta = (ExposeOnSpawn = "true"))
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

// FTransform Examples
// https://cpp.hotexamples.com/examples/-/FTransform/-/cpp-ftransform-class-examples.html

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/TargetPoint.h" 
#include "CompPath_Guided.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FImpact_02); // C++ Delegates

// C++ Component - Guided Turpedo -  Path Director

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPPCOMP_UE532_API UCompPath_Guided : public UActorComponent{
	GENERATED_BODY()

public:	
	UCompPath_Guided();

	// Guided Turpedo - set up varibale and move object
	UFUNCTION(BlueprintCallable, Category = "Guided Turpedo - setup values")
		void SetupValues(ATargetPoint* target_Point, float move_Speed);

	// Guided Turpedo- impact event 
	UPROPERTY(BlueprintAssignable, Category = "Guided Turpedo - impact event")
		FImpact_02 OnImpact;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	ATargetPoint* TargetPoint;
	float Speed = 500.f;
	bool Active = false;
	bool impact = false;
	FVector Target = FVector(FVector::ZeroVector);

	void Move();// moving based on an actor location --> TargetPoint  

	// temp vars
	FVector temp_01 = FVector(FVector::ZeroVector);
	float temp_02 = 0.f;

};

// C++ Delegates
// https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Delegates/index.html
// https://dev.epicgames.com/documentation/en-us/unreal-engine/delegates-and-lamba-functions-in-unreal-engine?application_version=5.3
// https://answers.unrealengine.com/questions/259969/blueprint-implementable-custom-component-events.html
// https://answers.unrealengine.com/questions/697849/creating-an-event-on-an-actorcomponent-in-c-for-bl.html
// Delegate type declarations must start with "F" character and recomended to have a "unique name"

#include "CPP_Torp_DEF.h"

ACPP_Torp_DEF::ACPP_Torp_DEF(){
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_Torp_DEF::BeginPlay(){
	Super::BeginPlay();	
	if (TargetPoint != nullptr) {
		Target = TargetPoint->GetActorLocation();
		//UE_LOG(LogTemp, Warning, TEXT("----------------------I just started running"));
		//UE_LOG(LogTemp, Error, TEXT("--- traget location: %s"), *TargetPlus.ToString());
		Active = true;
	}
}

void ACPP_Torp_DEF::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

	temp_02 = Speed * DeltaTime;
	if (Active)	Move();
	if (impact)	this->Destroy();


}
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

void ACPP_Torp_DEF::Move() {
	temp_01 = GetActorLocation();
	SetActorRotation(FRotationMatrix::MakeFromX(Target - temp_01).Rotator());
	temp_01 += (temp_02 * (Target - temp_01).GetSafeNormal());
	if ((FVector::Distance(Target, temp_01)) <= temp_02) {
		temp_01 = Target;
		impact = true;
	}
	SetActorLocation(temp_01);
}


//https://unrealcpp.com/debug-logging/ // Logging with UE_LOG
//https://michaeljcole.github.io/wiki.unrealengine.com/UE4_Transform_Calculus_-_Part_2/ // using Vector
//https://www.unrealengine.com/en-US/blog/ranged-based-for-loops // Range-Based For Loops


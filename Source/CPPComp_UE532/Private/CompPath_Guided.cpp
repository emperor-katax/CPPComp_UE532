#include "CompPath_Guided.h"

UCompPath_Guided::UCompPath_Guided(){
	PrimaryComponentTick.bCanEverTick = true;
}

void UCompPath_Guided::BeginPlay(){
	Super::BeginPlay();
}


void UCompPath_Guided::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	temp_02 = Speed * DeltaTime;
	if (Active) {
		Target = TargetPoint->GetActorLocation();
		Move();
	}
	if (impact)	OnImpact.Broadcast();
}

//////////////////////////////////////////////////////////////////

void UCompPath_Guided::Move() {
	temp_01 = this->GetOwner()->GetRootComponent()->GetComponentLocation();
	this->GetOwner()->GetRootComponent()->SetWorldRotation(FRotationMatrix::MakeFromX(Target - temp_01).Rotator());
	temp_01 += (temp_02 * (Target - temp_01).GetSafeNormal());
	if ((FVector::Distance(Target, temp_01)) <= temp_02) {
		temp_01 = Target;
		impact = true;
	}
	this->GetOwner()->GetRootComponent()->SetWorldLocation(temp_01);
}

void UCompPath_Guided::SetupValues(ATargetPoint* target_Point, float move_Speed) {
	if (target_Point != NULL) {
		TargetPoint = target_Point;
		Target = target_Point->GetActorLocation();
		Speed = move_Speed;
		//UE_LOG(LogTemp, Warning, TEXT("----------------------I just started running"));
		//UE_LOG(LogTemp, Error, TEXT("--- traget location: %s"), *TargetPlus.ToString());
		Active = true;
	}
}




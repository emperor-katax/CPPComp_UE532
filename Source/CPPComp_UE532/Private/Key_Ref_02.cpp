#include "Key_Ref_02.h"

AKey_Ref_02::AKey_Ref_02(){
	PrimaryActorTick.bCanEverTick = true;
}

void AKey_Ref_02::BeginPlay(){
	Super::BeginPlay();	
}

void AKey_Ref_02::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}

// ////C++ Function///////////////////////////////////////////

void AKey_Ref_02::setDistance() {}
void AKey_Ref_02::setName(FString name) {}
void AKey_Ref_02::setActive(bool bActive) {}

//void AKey_Ref_02::setActive_PRO(bool bActive = true, int value) {}		//	<-- ERROR --------------- !
//void AKey_Ref_02::setActive_PRO(int value, bool bActive = true) {}		//	<-- OK
//void AKey_Ref_02::setActive_PRO(bool bActive = true, int value = 4) {}	//	<-- OK

//void AKey_Ref_02::setActive_PRO(int value, bool bActive = true, int set = 4, bool bExtra = false) {} //	<-- OK
//void AKey_Ref_02::setActive_PRO(int value, bool bActive = true, int set    , bool bExtra = false) {} //	<-- not OK !


int AKey_Ref_02::getDistance() {
	// code
	return 0;
}

FString AKey_Ref_02::getName(int id) {
	// code
	return FString();
}

// ////BP Function/////////////////

bool AKey_Ref_02::isActive() {
	// code
	return false;
}

bool AKey_Ref_02::isExtra() {
	// code
	return false;
}


// /////BP Event///////////////////////

void AKey_Ref_02::SkillControl_Implementation() {
	// code
}

bool AKey_Ref_02::SkillMAX_Implementation() { 
	// code
	return false;
}




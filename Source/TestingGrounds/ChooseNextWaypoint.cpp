// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"

class BTNode;
class BlackboardComponent;
class AAIController;
class APatrollingGuard;


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	// TODO protect against empty patrol routes

	// Get Patrol Pints
	AAIController* AIControllerTT = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIControllerTT->GetPawn();
	APatrolingGuard* PatrollingGuard = Cast<APatrolingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;

	// Set Next waypoint 
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// cycle index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
	//UE_LOG(LogTemp, Warning, TEXT("HELLOWA: %s"), *name);
}



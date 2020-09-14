// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BTNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolingGuard.h" //TODO Remove coupling
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector IndexKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector WaypointKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	TArray<AActor*> PatrolPointsKey;
	
};

#pragma once
#include "Action.h"	
#include"Conditions.h"
#include <vector>

class State;

class Transition
{
public:
	Transition(State* linkTo, Condition* conditionsP);
	State* GetTargetState();

	bool IsTrigger();

	void ExecuteTransitionActions();
	


	Transition& operator=(const Transition& other)
	{
		this->isTrigger = other.isTrigger;
		this->transitionActions = other.transitionActions;
		this->condition = other.condition;
		this->targetState = other.targetState;
	}


private:
	bool isTrigger;
	State* targetState{ nullptr };
	std::vector<Action> transitionActions;
	Condition* condition;

	int id;

};
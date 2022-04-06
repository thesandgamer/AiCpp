#include "StateMachine.h"

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
}

void StateMachine::StartMachine()
{
	initialState = states[0];
	currentState = initialState;
}

void StateMachine::Update()
{
	Transition* triggeredTransition = nullptr;

	for (Transition* transition : currentState.GetTransitions())
	{
		if (transition->IsTrigger())
		{
			triggeredTransition = transition;
			break;
		}
	}

	if (triggeredTransition != nullptr)
	{
		State* targetState = triggeredTransition->GetTargetState();

		currentState.ExecuteExitActions();
		triggeredTransition->ExecuteTransitionActions();
		targetState->ExecuteEntryActions();

		currentState = *targetState;
	}
	else
	{
		currentState.ExecuteExitActions();
	}

}

void StateMachine::AddState(State newState)
{
	states.push_back(newState);
}

void StateMachine::AddStates(vector<State> newStates)
{
	states.insert(states.end(), newStates.begin(), newStates.end());
}

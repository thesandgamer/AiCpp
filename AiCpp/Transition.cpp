#include "Transition.h"
#include "State.h"

Transition::Transition(State* linkTo, Condition* conditionsP): targetState(linkTo), condition(conditionsP)
{
	isTrigger = false;
}

State* Transition::GetTargetState()
{
	return targetState;
}

bool Transition::IsTrigger()
{
	return condition->IsTriggered();;
}

void Transition::ExecuteTransitionActions()
{
	if (!transitionActions.empty())
	{
		for (Action ac : transitionActions)
		{
			ac.Execute();
		}
	}
}

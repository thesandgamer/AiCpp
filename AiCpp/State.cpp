#include "State.h"


//-------------------------------------
void State::ExecuteActions()
{
    for (Action action : actions)
    {
        action.Execute();
    }
}

void State::ExecuteEntryActions()
{
    for (Action action : entryActions)
    {
        action.Execute();
    }
}

void State::ExecuteExitActions()
{
    for (Action action : exitActions)
    {
        action.Execute();
    }
}
//--------------

vector<Transition*> State::GetTransitions()
{
    return transitions;
}

State::State()
{
    stateName = "Name Not defined";
}

State::State(std::string name): stateName(name)
{
}

State::~State()
{
}

void State::SetActions(vector<Action> newActions)
{
}

void State::SetEntryActions(vector<Action> newEntryActions)
{
}

void State::SetExitActions(vector<Action> newExitActions)
{
}

void State::AddAction(Action newAction)
{
    actions.push_back(newAction);

}

void State::AddEntryAction(Action newEntryAction)
{
    entryActions.push_back(newEntryAction);
}

void State::AddExitAction(Action newExitAction)
{
    exitActions.push_back(newExitAction);

}

void State::SetTransitions(vector<Transition*> newTransitions)
{
}

void State::AddTransition(Transition* newTransition)
{
}

void State::LinkStateToOther(State* otherState, Condition* condition)
{

    Transition* transition = new Transition(otherState, condition);
    transitions.push_back(transition);
}

void State::RemoveLink(const State* otherState)
{
    /*
    std::vector<Transition*>::iterator it = std::find(transitions.begin(), transitions.end(), otherState);
    transitions.erase( it);
    */
}

#include "State.h"

void State::ExecuteActions()
{
}

void State::ExecuteEntryActions()
{
}

void State::ExecuteExitActions()
{
}

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
}

void State::AddEntryAction(Action newEntryAction)
{
}

void State::AddExitAction(Action newExitAction)
{
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

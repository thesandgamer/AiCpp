#pragma once
#include "Action.h"
#include "Transition.h"

#include <vector>
#include <string>
using std::vector;


class State
{
public:
	State();
	State(std::string name );
	~State();

	//======== Preparation =========//
	//Rajoute les actions dans l'état
	void SetActions(vector<Action> newActions);
	void SetEntryActions(vector<Action> newEntryActions);
	void SetExitActions(vector<Action> newExitActions);

	void AddAction(Action newAction);
	void AddEntryAction(Action newEntryAction);
	void AddExitAction(Action newExitAction);

	void SetTransitions(vector<Transition*> newTransitions);
	void AddTransition(Transition* newTransition);



	void LinkStateToOther(State* otherState, Condition* condition);
	void RemoveLink(const State* otherState);

	//======== In Game ==========//

	//Effectue les actions
	void ExecuteActions();
	void ExecuteEntryActions();
	void ExecuteExitActions();

	vector<Transition*> GetTransitions();

	std::string GetStateName() { return stateName; };


	bool operator==(const State& other)
	{
		if (this->stateName == other.stateName) return true;
		return false;
	}

private:
	std::string stateName;

	vector<Transition*> transitions;

	vector<Action> actions;
	vector<Action> entryActions;
	vector<Action> exitActions;


};
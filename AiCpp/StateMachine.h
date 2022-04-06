#pragma once
#include <vector>
using std::vector;


#include "State.h"
#include "Transition.h"

using std::vector;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void StartMachine();
	void Update();

	void AddState(State newState);
	void AddStates(vector<State> newStates);

	State GetCurrentState() { return currentState; };

private:
	vector<State> states;

	State initialState;

	State currentState;

};
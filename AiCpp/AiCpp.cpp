#include <iostream>
#include <vector>

#include "StateMachine.h"
using std::cout;
using std::endl;


static void ExecuteActions(std::vector<Action>* actions)
{
	for (Action ac : *actions)
	{
		ac.Execute();
	}
}

void Update();

StateMachine machineTest;


int main()
{
	bool value = false;

	State base = State("Idle");
	State next = State("Run");
	BoolCondition* condition = new BoolCondition(&value); //Si 6 idle passe à run
	NotContidion* dnc = new NotContidion(*condition);	//Si autre que 6 passe à idle
	

	base.LinkStateToOther(&next, condition);
	next.LinkStateToOther(&base, dnc);

	machineTest.AddState(base);
	machineTest.AddState(next);

	machineTest.StartMachine();


	cout << "" << endl;

	int val;


	while (true)    // Detect window close button or ESC key
	{
		// Update
		Update();

		std::cin >> val;
		if (val == 0) value = false;
		if (val ==1) value = true;

	}
}

void Update()
{
	machineTest.Update();
	cout << machineTest.GetCurrentState().GetStateName() << endl;
}


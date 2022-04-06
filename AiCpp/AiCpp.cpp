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

void Run()
{
	std:cout << "The player is enter in running" << std::endl;
}


int main()
{
	bool isRunning = false;
	bool isAttacking = false;

	BoolCondition* runningCnd = new BoolCondition(&isRunning); //Si 6 idle passe à run
	NotContidion* notRunningCnd = new NotContidion(runningCnd);	//Si autre que 6 passe à idle

	Action runningAct = Action(&Run);

	State idle = State("Idle");
	State run = State("Run");
	State attack = State("Attack");

	run.AddEntryAction(runningAct);


	

	idle.LinkStateToOther(&run, runningCnd);
	run.LinkStateToOther(&idle, notRunningCnd);


	machineTest.AddStates({ idle,run,attack });

	machineTest.StartMachine();


	cout << "" << endl;



	while (true)    // Detect window close button or ESC key
	{
		// Update
		Update();
		
		std::cout << "Want to Run? ";
		std::cin >> isRunning;
		std::cout << std::endl;

	}
}

void Update()
{

	machineTest.Update();
	cout << "====" << machineTest.GetCurrentState().GetStateName() << "====" << endl;

}


#include "Action.h"

Action::Action(void(*function)()) : fcnPtr(function)
{
}

void Action::Execute()
{
	
	if (fcnPtr)
	{
		std::cout << "Execute" << std::endl;
		fcnPtr();

	}
}

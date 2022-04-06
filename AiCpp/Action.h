#pragma once
#include <iostream>

class Action
{
public:
	Action(void(*function)());
	void Execute();

private:
	void(*fcnPtr)();
};

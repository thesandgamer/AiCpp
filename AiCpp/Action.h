#pragma once
#include <iostream>

class Boss;

class Action
{
public:
	Action();
	Action(void(*function)());
	void Execute();

	void (*fcnPtr)();


private:
};

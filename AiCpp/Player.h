#pragma once
#include <iostream>

using std::cout;
using std::endl;

class Player
{
public:
	Player();

	void PlayerTurn();


	bool passTurn;

	float maxLife;
	float currentLife;
};

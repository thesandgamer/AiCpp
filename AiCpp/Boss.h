#pragma once
#include <iostream>
#include <vector>

#include "StateMachine.h"


using std::cout;
using std::endl;

class Boss
{
public:
	float nbAttack = 0;
	StateMachine machineTest;

	Boss();

	void SetupBoss();
	void BossTurn();

	void Attack(int chanceToAtt1, int chanceToAtt2, int chanceToAtt3);


	void AttackNormal();
	void AttackBerserk();
	void AttackFury();


	void SwordSlash();

	void Slam();

	void Charge();


	float maxLife;
	float currentLife;

	//Pointeur vers son adversaire

private:



};


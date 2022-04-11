#include "Boss.h"


Boss::Boss()
{
}

void Boss::SetupBoss()
{

	FloatCondition* threeAttackCnd = new FloatCondition(FloatConditionTypes::superior, 3, 0, &nbAttack);
	FloatCondition* sevenAttackCnd = new FloatCondition(FloatConditionTypes::superior, 7, 0, &nbAttack);

	//Action attackNormalAct = Action(&Boss::AttackNormal);
	Action attackNormalAct = Action();
	Action attackBerserkAct = Action(&Boss::AttackBerserk);
	Action attackFuryAct = Action(&AttackFury);

	State normal = State("Normal");
	State berserk = State("Berserk");
	State fury = State("Fury");

	normal.AddAction(attackNormalAct);
	berserk.AddAction(attackBerserkAct);
	fury.AddAction(attackFuryAct);




	normal.LinkStateToOther(&berserk, threeAttackCnd);
	berserk.LinkStateToOther(&fury, sevenAttackCnd);


	machineTest.AddStates({ normal,berserk,fury });

	machineTest.StartMachine();
}

void Boss::BossTurn()
{
	cout << endl << endl << "//=============================BOSS TURN=============================\\" << endl;
	machineTest.Update();
}

void Boss::Attack(int chanceToAtt1, int chanceToAtt2, int chanceToAtt3)
{
std:cout << "The boss is attaking" << std::endl;
	int number = rand() % 100;
	//number = 10 - number;

	if (number < chanceToAtt1)
	{
		SwordSlash();
	}
	else if (number < chanceToAtt1 + chanceToAtt2 && number > chanceToAtt1)
	{
		Slam();
	}
	else if (number < chanceToAtt1 + chanceToAtt2 + chanceToAtt3 && number > chanceToAtt1 + chanceToAtt2)
	{
		Charge();
	}

	nbAttack++;
}

void Boss::AttackNormal()
{
	int number = rand() % 100;
	if (number >= 50)
	{
		Attack(70, 20, 10);
	}
	else
	{
		cout << "Attack miss" << endl;
	}
}

void Boss::AttackFury()
{
	int number = rand() % 100;
	if (number >= 22.22f)
	{
		Attack(20, 30, 50);
	}
	else
	{
		cout << "Attack miss" << endl;
	}
}

void Boss::SwordSlash()
{
	cout << "Sword slash" << endl;

}

void Boss::Slam()
{
	cout << "Slam" << endl;

}

void Boss::Charge()
{
	cout << "Charge" << endl;
}

void Boss::AttackBerserk()
{
	int number = rand() % 100;
	if (number >= 33.33f)
	{
		Attack(20, 50, 30);
	}
	else
	{
		cout << "Attack miss" << endl;
	}
}


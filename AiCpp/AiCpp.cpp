#include <iostream>
#include <vector>

#include "Boss.h"
#include "Player.h"
using std::cout;
using std::endl;




void Update();


Boss mainBoss;
Player mainPlayer;

int main()
{
	srand(time(NULL));



	cout << "" << endl;

	mainBoss.SetupBoss();
	while (true)    // Detect window close button or ESC key
	{
		// Update
		Update();


	}
}



void Update()
{


	mainPlayer.PlayerTurn();
	mainBoss.BossTurn();

	cout << "====" << mainBoss.machineTest.GetCurrentState().GetStateName() << "====" << endl;

}


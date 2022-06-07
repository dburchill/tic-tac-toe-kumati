//


#include <iostream>
#include "Game.h"


 
int main()
{
	Game game;

	while (true)
	{
		game.choosePlayers();
		game.play();
		system("pause");
	}
}
#include <iostream>
#include "SolarSystemGame.h"

int main()
{
	SolarSystemGame* game = new SolarSystemGame(L" Solar System ", 1200, 1200);
	game->Run();
	return EXIT_SUCCESS;
}

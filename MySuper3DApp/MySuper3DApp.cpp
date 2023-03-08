#include <iostream>
#include "KatamariDamacy.h"

int main()
{
	KatamariDamacy* game = new KatamariDamacy(L" Katamari Damacy ", 1200, 1200);
	game->Run();
	return EXIT_SUCCESS;
}

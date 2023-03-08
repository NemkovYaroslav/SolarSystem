#pragma once
#include "Game.h"

class Planet;

class KatamariDamacy : public Game
{
public:

	KatamariDamacy(LPCWSTR name, int clientWidth, int clientHeight);

	void Initialize();
	void Run();
};

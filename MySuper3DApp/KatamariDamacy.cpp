#include "KatamariDamacy.h"
#include "DebugObject.h"
#include "KatamariObject.h"

KatamariDamacy::KatamariDamacy(LPCWSTR name, int clientWidth, int clientHeight) : Game(name, clientWidth, clientHeight)
{
	Game::CreateInstance(name, clientWidth, clientHeight);
	Initialize();
}

void KatamariDamacy::Initialize()
{
	DebugObject* grid = new DebugObject();
	grid->CreateGrid(20, 1.0f, Color(1.0f, 0.5f, 1.0f, 1.0f));
	Game::GetInstance()->AddGameObject(grid);

	KatamariObject* sun = new KatamariObject();
	sun->CreateSphere(1.0f);
	sun->SetPosition(Vector3::Zero);
	sun->rotationAxis = Vector3::UnitY;
	sun->orbitSpeed = 0.2f;
	sun->rotationSpeed = 1;

	KatamariObject* earth = new KatamariObject(sun);
	earth->CreateSphere(0.5f);
	earth->SetPosition(Vector3(1, 0, 1) * 1.5);
	earth->rotationAxis = Vector3(0, 1, 0);
	earth->orbitAxis = Vector3(0, 1, 0);
	earth->orbitSpeed = 0.2f;
	earth->rotationSpeed = 1;

	KatamariObject* moon = new KatamariObject(earth);
	moon->CreateSphere(0.15f);
	moon->SetPosition(Vector3(1, 0, 1) * 0.58);
	moon->rotationAxis = Vector3(0, 1, 0);
	moon->orbitAxis = Vector3(0, 1, 0);
	moon->orbitSpeed = 1.0f;
	moon->rotationSpeed = 5;

	Game::GetInstance()->AddGameObject(sun);
	Game::GetInstance()->AddGameObject(earth);
	Game::GetInstance()->AddGameObject(moon);
}

void KatamariDamacy::Run()
{
	Game::GetInstance()->Run();
}
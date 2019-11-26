//------------------------------------------------------------------------------
//
// File Name:	MainMenu.cpp
// Author(s):	Frank Bartkus (frank.bartkus)
// Project:		BetaFramework
// Course:		WANIC VGP2 2019-2020
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Level1.h"
#include "Instructions.h"
#include "PlayerShip.h"

//------------------------------------------------------------------------------

using namespace Beta;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Creates an instance of Level 1.
Instructions::Instructions()
	: Level("Instructions"), testObject(nullptr)
{
}

void Instructions::Load()
{
	spriteSource = ResourceGetSpriteSource("Circle");
}

// Initialize the memory associated with the Level1 game state.
void Instructions::Initialize()
{
	std::cout << "WinLevel: Initialize" << std::endl;

	// Create a new game object
	testObject = new GameObject("TestObject");

	// Create a transform component at 0,0 with scale 300,300
	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	float y = 4.0f;
	transform->SetScale(Vector2D(y * 1.61803399, y));
	testObject->AddComponent(transform);

	// Create a sprite component and set its mesh and sprite source
	Sprite* sprite = new Sprite();
	sprite->SetSpriteSource(ResourceGetSpriteSource("Instructions"));
	testObject->AddComponent(sprite);

	// Add object to object manager
	GetSpace()->GetObjectManager().AddObject(*testObject);
}

// Update the Level1 game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Instructions::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	Input* input = EngineGetModule(Input);

	// If the user presses the '1' key, restart the current level
	if (input->CheckTriggered(32))
		GetSpace()->SetLevel<Level1>();
}

// Shutdown any memory associated with the Level1 game state.
void Instructions::Shutdown()
{
	std::cout << "MainMenu::Shutdown" << std::endl;
}

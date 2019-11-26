//------------------------------------------------------------------------------
//
// File Name:	MainMenu.h
// Author(s):	Frank Bartkus (frank.bartkus)
// Project:		BetaFramework
// Course:		WANIC VGP2 2019-2020
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Level.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward Declarations:
//------------------------------------------------------------------------------
namespace Beta
{
	class GameObject;
	class SpriteSource;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class MainMenu : public Beta::Level
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Creates an instance of Level 1.
	MainMenu();

	// Load assets associated with Level 1.
	void Load() override;

	// Initialize the memory associated with Level 1.
	void Initialize() override;

	// Update Level 1.
	// Params:
	//	 dt = Change in time (in seconds) since the last game loop.
	void Update(float dt) override;

	// Shutdown any memory associated with Level 1.
	void Shutdown() override;

private:
	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	Beta::GameObject* testObject;
	Beta::SpriteSourcePtr spriteSource;
};

//----------------------------------------------------------------------------

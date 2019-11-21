//------------------------------------------------------------------------------
//
// File Name:	Archetypes.h
// Author(s):	Christian Yan
// Project:		Shadow Hunters
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include <Component.h>

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward Declarations:
//------------------------------------------------------------------------------

namespace Beta
{
	class GameObject;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

namespace Archetypes
{
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Create a game object that uses the Ship texture.
	// Returns:
	//	 A pointer to the newly constructed game object
	Beta::GameObject* CreatePlayer();

	// Create a game object archetype that uses the Bullet texture.
	// Returns:
	//	 A pointer to the newly constructed game object
	Beta::Archetype CreateBulletArchetype();

	// Create a game object archetype that uses the Asteroid texture.
	// Returns:
	//	 A pointer to the newly constructed game object
	Beta::Archetype CreateEnemyArchetype();
	// Create a game object archetype that uses the Asteroid texture.
	// Returns:
	//	 A pointer to the newly constructed game object
	Beta::Archetype CreateRealEnemyArchetype();
}

//----------------------------------------------------------------------------
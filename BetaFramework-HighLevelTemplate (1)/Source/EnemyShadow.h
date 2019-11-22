//------------------------------------------------------------------------------
//
// File Name:	EnemyShadow.h
// Author(s):	Christian Yan
// Project:		Shadow Hunters
// Course:		WANIC VGP2 2018-2019
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Component.h" // base class
#include "PlayerShip.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward Declarations:
//------------------------------------------------------------------------------

namespace Beta
{
	class Transform;
	class RigidBody;
	class GameObject;
	struct Event;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class EnemyShadow : public Beta::Component
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Asteroid constructor
	// Params:
	//   speedMin = Minimum of range for asteroid movement speed.
	//   speedMax = Maximum of range for asteroid movement speed.
	//   basePointsValue = Point value for largest asteroid.
	EnemyShadow(float speed = 0.5f, float size = 0.0f, bool newPos = true);

	// Initialize this component (happens at object creation).
	void Initialize() override;

private:
	//------------------------------------------------------------------------------
	// Private Functions:EnemyShadow
	//------------------------------------------------------------------------------

	// The collision handling function for Asteroids.
	// Params:
	//	 event = The collision event object.
	void OnCollisionStarted(const Beta::Event& event);

	// Set position of asteroid based on origin
	void SetPosition();

	// Set velocity based on size
	void SetVelocity();

	// Generate new asteroids based off this asteroid
	void SpawnNewEnemyShadow();
	
	//get the player ship
	void SetPlayerShip(Beta::GameObject* player);

	//------------------------------------------------------------------------------
	// Private Structures:
	//------------------------------------------------------------------------------

	enum Size
	{
		SizeSmall,
		SizeMedium,
		SizeLarge,
	};

	enum Location
	{
		LocationTopLeft,
		LocationTopRight,
		LocationBottomLeft,
		LocationBottomRight,
	};

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Properties (save to/load from file)
	float speed;

	// Other variables
	float size;

	Location location;

	bool newPos;

	// Components
	Beta::Transform* transform;
	Beta::RigidBody* rigidBody;

	Beta::GameObject* player;

	COMPONENT_SUBCLASS_DECLARATION(EnemyShadow)
};

//------------------------------------------------------------------------------
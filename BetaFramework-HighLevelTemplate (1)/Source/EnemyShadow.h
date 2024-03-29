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
	class Vector2D;
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
	// speed = how fast the ship will go
	// newPos = when to get the new position
	// maximumSpeed = the fastest the enemy will be able to go
	EnemyShadow(float speed = 1.0f, bool newPos = true, float maximumSpeed = 2.0f);

	// Initialize this component (happens at object creation).
	void Initialize() override;

	void Update(float dt) override;

	//get the player ship
	void SetPlayerShip(Beta::GameObject* player);

	void BecomeReal();

private:
	//------------------------------------------------------------------------------
	// Private Functions:EnemyShadow
	//------------------------------------------------------------------------------

	// The collision handling function for Enemy.
	// Params:
	//	 event = The collision event object.
	void OnCollisionStarted(const Beta::Event& event);

	// Set position of enemy based on origin
	void SetPosition();

	// Set velocity
	void SetVelocity(Beta::Vector2D randNum);
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

	float speed;
	bool newPos;
	bool real;
	float timer;
	float maximumSpeed;

	Beta::Vector2D randPos;

	// Components
	Beta::Transform* transform;
	Beta::RigidBody* rigidBody;

	Beta::GameObject* player;

	COMPONENT_SUBCLASS_DECLARATION(EnemyShadow)
};

//------------------------------------------------------------------------------

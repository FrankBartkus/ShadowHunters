//------------------------------------------------------------------------------
//
// File Name:	PlayerProjectile.cpp
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "PlayerProjectile.h"
#include "PlayerShip.h"

//------------------------------------------------------------------------------

using namespace Beta;


// STUDENT CODE GOES HERE
	// Default constructor
PlayerProjectile::PlayerProjectile()
	: Component("PlayerProjectile"), player(nullptr), transform(nullptr), rigidBody(nullptr)
{
}
// Initialize this component (happens at object creation).
void PlayerProjectile::Initialize()
{
	RegisterEventHandler(GetOwner(), "CollisionStarted", &PlayerProjectile::OnCollisionStarted);
	transform = GetOwner()->GetComponent<Transform>();
	rigidBody = GetOwner()->GetComponent<RigidBody>();
}

#pragma warning(push)
#pragma warning(disable : 26451)
// Update the Bullet.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void PlayerProjectile::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	Array<GameObject*>Asteroids;
	GameObject* Target = nullptr;
}
// The collision handling function for Asteroids.
// Params:
//	 event = The collision event object.
void PlayerProjectile::OnCollisionStarted(const Beta::Event& event)
{
	const CollisionEvent& collision = static_cast<const CollisionEvent&>(event);
	if (collision.otherObject.GetName() == "Asteroid")
	{
		GetOwner()->Destroy();
	}
}


//------------------------------------------------------------------------------

// Extra component stuff - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(PlayerProjectile)
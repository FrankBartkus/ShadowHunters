//------------------------------------------------------------------------------
//
// File Name:	Archetypes.cpp
// Author(s):	Christian Yan
// Project:		Shadow Hunters
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Archetypes.h"
using namespace Beta;
Beta::GameObject* Archetypes::CreatePlayer()
{
	//create the game object
	GameObject* shipObject = new GameObject("Ship");
	//get the transform
	Transform* transform = new Transform(0.0f, 0.0f);
	//set the scale
	transform->SetScale(Vector2D(0.5f, 0.5f));
	//get the rigidbody
	RigidBody* rigidbody = new RigidBody();
	//get the sprite
	Sprite* sprite = new Sprite();
	sprite->SetSpriteSource(ResourceGetSpriteSource("PlayerShip"));

	//add the collider and set the radius
	ColliderCircle* collider = new ColliderCircle();
	collider->SetRadius(transform->GetScale().x / 2);

	//adds the components to the ship object
	shipObject->AddComponent(sprite);
	shipObject->AddComponent(rigidbody);
	shipObject->AddComponent(transform);
	//shipObject->AddComponent(playership);
	//shipObject->AddComponent(screenWrap);

	return shipObject;
	return nullptr;
}

Beta::Archetype Archetypes::CreateBulletArchetype()
{
	return Beta::Archetype();
}

Beta::Archetype Archetypes::CreateEnemyArchetype()
{
	return Beta::Archetype();
}

Beta::Archetype Archetypes::CreateRealEnemyArchetype()
{
	return Beta::Archetype();
}

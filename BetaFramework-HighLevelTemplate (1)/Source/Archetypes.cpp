//------------------------------------------------------------------------------
//
// File Name:	Archetypes.cpp
// Author(s):	Christian Yan
// Project:		Shadow Hunters
// Course:		WANIC VGP2 2018-2019
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Archetypes.h"
#include "EnemyShadow.h"
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
}

Beta::Archetype Archetypes::CreateBulletArchetype()
{
	//create the bullet object
	GameObject* bulletObject = new GameObject("Bullet");
	//get the transform
	Transform* transform = new Transform(0.0f, 0.0f);
	//set the scale
	transform->SetScale(Vector2D(0.07f, 0.07f));
	//get the rigidbody
	RigidBody* rigidbody = new RigidBody();
	//get the sprite
	Sprite* sprite = new Sprite();
	//get the timed death
	//TimedDeath* timedDeath = new TimedDeath();
	sprite->SetSpriteSource(ResourceGetSpriteSource("Bullet"));
	// get the player projectile
	//PlayerProjectile* playerProjectile = new PlayerProjectile();

	//add the components to the bulletObject
	bulletObject->AddComponent(sprite);
	bulletObject->AddComponent(rigidbody);
	bulletObject->AddComponent(transform);
	//bulletObject->AddComponent(timedDeath);
	//bulletObject->AddComponent(playerProjectile);
	EngineGetModule(GameObjectFactory)->SaveObjectToFile(bulletObject);

	return Archetype(bulletObject);
}

Beta::Archetype Archetypes::CreateEnemyArchetype()
{
	//create the game object
	GameObject* enemyObject = new GameObject("enemy");
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

	//add the enemy movemen
	EnemyShadow* enemyShadow = new EnemyShadow();

	//adds the components to the ship object
	enemyObject->AddComponent(sprite);
	enemyObject->AddComponent(rigidbody);
	enemyObject->AddComponent(transform);
	enemyObject->AddComponent(enemyShadow);
	return Beta::Archetype();
}
//------------------------------------------------------------------------------
//
// File Name:	EnemyShadow.h
// Author(s):	Christian Yan
// Project:		Shadow Hunters
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "EnemyShadow.h"
using namespace Beta;
EnemyShadow::EnemyShadow(float speed, float size,bool newPOS, float findNewPos,float maximumSpeed)
	: Component("EnemyShadow"), speed(speed),size(size), rigidBody(nullptr), transform(nullptr), 
	location(LocationTopLeft), player(nullptr),newPos(newPOS),timer(0), findNewPos(findNewPos), maximumSpeed(maximumSpeed), real(false),
	randPos(Vector2D(0.0f,0.0f))
{
}

void EnemyShadow::Initialize()
{
	// get the components
	rigidBody = GetOwner()->GetComponent<Beta::RigidBody>();
	transform = GetOwner()->GetComponent<Beta::Transform>();
	//call the event handler
	RegisterEventHandler(GetOwner(), "CollisionStarted", &EnemyShadow::OnCollisionStarted);
	//call these functions
	SetPosition();
}

void EnemyShadow::Update(float dt)
{
	if (newPos)
	{
		randPos = Vector2D(Random::Range(-1.0f, 1.0f), Random::Range(-1.0f, 1.0f));
		timer = 3;
		newPos = false;
	}
	timer -= dt;
	if (timer < 0)
	{
		newPos = true;
	}
	SetVelocity(randPos);
}

void EnemyShadow::OnCollisionStarted(const Beta::Event& event)
{
	//check if the asteroid got hit by either bullet or spaceship
	const Beta::CollisionEvent& ce = static_cast<const Beta::CollisionEvent&>(event);
	if (ce.otherObject.GetName() == "Bullet" || ce.otherObject.GetName() == "SpaceShip")
	{
		if (real)
		{
			GameObjectFactory* gameObjectFactory = EngineGetModule(GameObjectFactory);
			GameObject* key = gameObjectFactory->CreateObject("key");
			Vector2D direction = Vector2D::FromAngleRadians(transform->GetRotation());
			key->GetComponent<Transform>()->SetTranslation(transform->GetTranslation());
			key->GetComponent<Transform>()->SetRotation(0);
			GetOwner()->GetSpace()->GetObjectManager().AddObject(*key);
		}
		GetOwner()->Destroy();
	}
}

void EnemyShadow::SpawnEnemy()
{
}

void EnemyShadow::SetPosition()
{
	BoundingRectangle screenDim = GetSpace()->GetCamera().GetScreenWorldDimensions();
	//get a random number
	int rand = Random::Range(0, 3);
	// change the translation depending on the random number
	switch (rand)
	{
	case LocationTopLeft:
		transform->SetTranslation(Vector2D(screenDim.left, screenDim.top));
		break;
	case LocationTopRight:
		transform->SetTranslation(Vector2D(screenDim.right, screenDim.top));
		break;
	case LocationBottomLeft:
		transform->SetTranslation(Vector2D(screenDim.left, screenDim.bottom));
		break;
	case LocationBottomRight:
		transform->SetTranslation(Vector2D(screenDim.right, screenDim.bottom));
		break;
	}
}

void EnemyShadow::SetVelocity(Vector2D randNum)
{
	//get the directio that the ship should face and add a random diretion
	Vector2D pos = player->GetComponent<Transform>()->GetTranslation();
	Vector2D direction = ((pos + randNum) - transform->GetTranslation()).Normalized();
	rigidBody->SetVelocity(direction * speed);

	transform->SetRotation(atan2(direction.y,direction.x));
	if (rigidBody->GetVelocity().Magnitude() > maximumSpeed)
	{
		rigidBody->SetVelocity(rigidBody->GetVelocity().Normalized() * maximumSpeed);
	}
}

void EnemyShadow::SetPlayerShip(GameObject* player_)
{
	player = player_;
}
void EnemyShadow::BecomeReal()
{
	real = true;
}

COMPONENT_SUBCLASS_DEFINITION(EnemyShadow)
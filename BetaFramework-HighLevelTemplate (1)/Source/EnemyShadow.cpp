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
#include "stdafx.h"
#include "EnemyShadow.h"
using namespace Beta;
EnemyShadow::EnemyShadow(float speed, float size,bool newPOS, float findNewPos)
	: Component("EnemyShadow"), speed(speed),size(size), rigidBody(nullptr), transform(nullptr), 
	location(LocationTopLeft), player(nullptr),newPos(newPOS),timer(0), findNewPos(findNewPos)
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
		timer = 3;
		SetVelocity();
		newPos = false;
	}
	timer -= dt;
	if (timer < 0)
	{
		newPos = true;
	}
}

void EnemyShadow::OnCollisionStarted(const Beta::Event& event)
{
	//check if the asteroid got hit by either bullet or spaceship
	const Beta::CollisionEvent& ce = static_cast<const Beta::CollisionEvent&>(event);
	if (ce.otherObject.GetName() == "Bullet" || ce.otherObject.GetName() == "SpaceShip")
	{
		GetOwner()->Destroy();
	}
}

void EnemyShadow::SetPosition()
{
	BoundingRectangle screenDim = GetSpace()->GetCamera().GetScreenWorldDimensions();
	if (size == SizeLarge)
	{
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
}

void EnemyShadow::SetVelocity()
{
	Vector2D rand = Vector2D(Random::Range(0, 1), Random::Range(0, 1));
	Vector2D pos = player->GetComponent<Transform>()->GetTranslation();
	Vector2D direction = (Vector2D::FromAngleRadians(player->GetComponent<Transform>()->GetRotation()).Normalized());
	rigidBody->SetVelocity(direction * speed);

	transform->SetRotation(atan2(direction.y,direction.x));
}

void EnemyShadow::SetPlayerShip(GameObject* player_)
{
	player = player_;
}

COMPONENT_SUBCLASS_DEFINITION(EnemyShadow)
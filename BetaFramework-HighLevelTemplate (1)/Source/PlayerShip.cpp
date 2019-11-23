//------------------------------------------------------------------------------
//
// File Name:	PlayerShip.cpp
// Author(s):	Frank Bartkus (frank.bartkus)
// Project:		BetaFramework
// Course:		WANIC VGP2 2019-2020
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "PlayerShip.h"
#include "WinLevel.h"

//------------------------------------------------------------------------------

using namespace Beta;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Student code goes here.
	// Default constructor
	// Params:
	//   bulletArchetype = The archetype for the bullet.
	//   forwardThrust = Amount of force added to the ship when thrusters are activated.
	//   maximumSpeed  = Maximum attainable speed of the ship.
	//   rotationSpeed = Speed at which the ship rotates.
	//   bulletSpeed   = Speed at which bullets move when fired by ship.
PlayerShip::PlayerShip(Beta::Archetype bulletArchetype, float forwardThrust, float maximumSpeed, float rotationSpeed, float bulletSpeed, float deathDuration)
	: Component("PlayerShip"), bulletArchetype(bulletArchetype), forwardThrust(forwardThrust), maximumSpeed(maximumSpeed), rotationSpeed(rotationSpeed), bulletSpeed(bulletSpeed), deathDuration(deathDuration), transform(nullptr), timer(0), score(0), rigidBody(nullptr), isDying(false)
{

}
// Initialize this component (happens at object creation).
void PlayerShip::Initialize()
{
	RegisterEventHandler(GetOwner(), "CollisionStarted", &PlayerShip::OnCollisionStarted);
	transform = GetOwner()->GetComponent<Transform>();
	rigidBody = GetOwner()->GetComponent<RigidBody>();
}
// Update function for this component.
// Params:
//   dt = The (fixed) change in time since the last step.
void PlayerShip::Update(float dt)
{
	if (isDying)
	{
		DeathSequence(dt);
	}
	else
	{
		Move();
		Rotate();
		Shoot();
	}
}
// Move forward when up arrow is pressed
void PlayerShip::Move() const
{
	Input& input = *EngineGetModule(Input);
	if (input.CheckHeld(VK_UP))
	{
		rigidBody->AddForce(Vector2D::FromAngleRadians(transform->GetRotation()) * forwardThrust);
	}
	else
	{
		rigidBody->AddForce(-rigidBody->GetVelocity().Normalized());
	}
	if (rigidBody->GetVelocity().Magnitude() > maximumSpeed)
	{
		rigidBody->SetVelocity(rigidBody->GetVelocity().Normalized() * maximumSpeed);
	}
}
// Rotate when left or right arrow key is pressed
void PlayerShip::Rotate() const
{
	Input& input = *EngineGetModule(Input);
	if (input.CheckHeld(VK_LEFT) || input.CheckHeld(VK_RIGHT))
	{
		if (input.CheckHeld(VK_RIGHT))
		{
			rigidBody->SetAngularVelocity(-rotationSpeed);
		}
		if (input.CheckHeld(VK_LEFT))
		{
			rigidBody->SetAngularVelocity(rotationSpeed);
		}
	}
	else
	{
		rigidBody->SetAngularVelocity(0);
	}
}
// Shoot projectiles when space is pressed
void PlayerShip::Shoot()
{
	Input& input = *EngineGetModule(Input);
	if (input.CheckTriggered(VK_SPACE))
	{
		GameObjectFactory* gameObjectFactory = EngineGetModule(GameObjectFactory);
		GameObject* bullet = gameObjectFactory->CreateObject("Bullet");
		Vector2D direction = Vector2D::FromAngleRadians(transform->GetRotation());
		bullet->GetComponent<Transform>()->SetTranslation(transform->GetTranslation() + Vector2D::FromAngleRadians(transform->GetRotation()) / 4);
		bullet->GetComponent<Transform>()->SetRotation(transform->GetRotation());
		bullet->GetComponent<RigidBody>()->SetVelocity(direction * bulletSpeed + rigidBody->GetVelocity());
		GetOwner()->GetSpace()->GetObjectManager().AddObject(*bullet);
	}
}
// Execute the death "animation" for the ship.
// Params:
//   dt = Change in time since the last frame.
void PlayerShip::DeathSequence(float dt)
{
	rigidBody->SetAngularVelocity(30.0f);
	rigidBody->SetVelocity(Vector2D(0, 0));
	if ((int)(timer * 20) % 2 == 0)
	{
		GetOwner()->GetComponent<Sprite>()->SetColor(Colors::Red);
	}
	else
	{
		GetOwner()->GetComponent<Sprite>()->SetColor(Colors::White);
	}
	transform->SetScale(timer / 4);
	if (timer <= 0)
	{
		GetOwner()->Destroy();
		GetSpace()->RestartLevel();
	}
	timer -= dt;
}
// Respond to collision events.
void PlayerShip::OnCollisionStarted(const Beta::Event& event)
{
	const CollisionEvent& collision = static_cast<const CollisionEvent&>(event);
	if (!isDying)
	{
		if (collision.otherObject.GetName() == "EnemyShip")
		{
			isDying = true;
			timer = deathDuration;
		}
		if (collision.otherObject.GetName() == "Key")
		{
			GameObject* door = new GameObject("Door");
			ColliderRectangle* colliderRectangle = new ColliderRectangle();
			colliderRectangle->SetExtents(Vector2D(0.25 / 1.61803399, 0.25));
			door->AddComponent(colliderRectangle);
			Transform* doorTransform = new Transform(0.0f, 0.0f);
			doorTransform->SetRotation(0.0f);
			doorTransform->SetScale(Vector2D(0.5 / 1.61803399, 0.5f));
			Vector2D newPosition;
			do
			{
				newPosition = Vector2D(Random::Range(GetSpace()->GetCamera().GetScreenWorldDimensions().left, GetSpace()->GetCamera().GetScreenWorldDimensions().right),
					Random::Range(GetSpace()->GetCamera().GetScreenWorldDimensions().bottom, GetSpace()->GetCamera().GetScreenWorldDimensions().top));
			} while (doorTransform->GetTranslation().Distance(newPosition) < 2.0f);
			doorTransform->SetTranslation(newPosition);
			door->AddComponent(doorTransform);
			Sprite* sprite = new Sprite();
			sprite->SetSpriteSource(ResourceGetSpriteSource("Door"));
			door->AddComponent(sprite);
			GetOwner()->GetSpace()->GetObjectManager().AddObject(*door);
			collision.otherObject.Destroy();
		}
		if (collision.otherObject.GetName() == "Door")
		{
			GetSpace()->SetLevel<WinLevel>();
		}
	}
}

// Extra component functionality - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(PlayerShip)

//------------------------------------------------------------------------------


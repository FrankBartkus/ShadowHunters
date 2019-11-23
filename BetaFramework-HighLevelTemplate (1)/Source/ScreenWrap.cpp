//------------------------------------------------------------------------------
//
// File Name:	ScreenWrap.cpp
// Author(s):	Christian Yan (c.yan)
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
#include "ScreenWrap.h"

//------------------------------------------------------------------------------

using namespace Beta;


// STUDENT CODE GOES HERE






//------------------------------------------------------------------------------

// Extra component stuff - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(ScreenWrap)

ScreenWrap::ScreenWrap()
	:Component("ScreenWrap"),rigidBody(nullptr),transform(nullptr)
{
}

void ScreenWrap::Initialize()
{
	//get the components
	std::cout << "ScreenWrap::Initialize" << std::endl;
	transform = GetOwner()->GetComponent<Transform>();
	rigidBody = GetOwner()->GetComponent<RigidBody>();
}

void ScreenWrap::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	//get the translation scale and velocity
	Vector2D translation = GetOwner()->GetComponent<Transform>()->GetTranslation();
	Vector2D scale = GetOwner()->GetComponent<Transform>()->GetScale();
	Vector2D velocity = GetOwner()->GetComponent<RigidBody>()->GetVelocity();
	BoundingRectangle screenSize = GetSpace()->GetCamera().GetScreenWorldDimensions();
	//check what direction the velocity is and if it went off the screen
	//if it did then set it to the other side
	if (velocity.x > 0 && translation.x > screenSize.right + scale.x)
	{
		transform->SetTranslation(Vector2D(screenSize.left - scale.x,translation.y));
	}
	if (velocity.x < 0 && translation.x  < screenSize.left - scale.x)
	{
		transform->SetTranslation(Vector2D(screenSize.right + scale.x, translation.y));
	}
	if (velocity.y > 0 && translation.y > screenSize.top + scale.y)
	{
		transform->SetTranslation(Vector2D(translation.x, screenSize.bottom - scale.y));
	}
	if (velocity.y < 0 && translation.y  < screenSize.bottom - scale.y)
	{
		transform->SetTranslation(Vector2D(translation.x, screenSize.top + scale.y));
	}

}

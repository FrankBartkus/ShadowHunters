//------------------------------------------------------------------------------
//
// File Name:	TimedDeath.cpp
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
#include "TimedDeath.h"
#include "PlayerProjectile.h"

//-------------------------------------------------------------------------------

using namespace Beta;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Student code goes here.
	// Params:
	//   timeUntilDeath = Amount of time until the object self-destructs.
TimedDeath::TimedDeath(float timeUntilDeath) : Component("TimedDeath"), timeUntilDeath(timeUntilDeath)
{

}
// Update function for this component.
// Params:
//   dt = The (fixed) change in time since the last step.
void TimedDeath::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	timeUntilDeath -= dt;
	if (timeUntilDeath <= 0)
	{
		GetOwner()->Destroy();
	}
}
// Write object data to file
// Params:
//   parser = The parser that is writing this object to a file.
void TimedDeath::Serialize(Beta::FileStream & stream) const
{
	stream.WriteVariable("timeUntilDeath", timeUntilDeath);
}
// Read object data from a file
// Params:
//   parser = The parser that is reading this object's data from a file.
void TimedDeath::Deserialize(Beta::FileStream & stream)
{
	stream.ReadVariable("timeUntilDeath", timeUntilDeath);
}

// Extra component functionality - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(TimedDeath)

//------------------------------------------------------------------------------

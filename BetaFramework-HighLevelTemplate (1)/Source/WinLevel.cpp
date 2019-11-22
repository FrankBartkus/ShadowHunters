#include "stdafx.h"
#include "WinLevel.h"

#include "curses.h" // Colors

#include "GameObject.h" // GameObject
#include "Vector2D.h" // Vector2D
#include "Wall.h" // Collisions
#include "Engine.h" // DrawText
#include "ObjectManager.h" // AddObject, DestroyAllObjects

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------


static const float levelWidth = 49.0f;
static const float levelHeight = 19.0f;

static const Vector2D levelCenter = { 35.0f, 15.0f };


//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Initialize the memory associated with the Level2 game state.
void YouWinInit(void)
{
	// Create a color pair to use later
	EngineSetColorPair(0, COLOR_WHITE, COLOR_RED);
}

// Update the Level2 game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void YouWinUpdate(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	float x = 0.0;
	float y = -6.0;
	// Draw level title
	EngineDrawText("_____.___.               __      __.__      ._.", COLOR_RED, levelCenter.x - x, levelCenter.y + y);
	EngineDrawText("\\__  |   | ____  __ __  /  \\    /  \\__| ____| |", COLOR_RED, levelCenter.x - x, levelCenter.y + y + 1);
	EngineDrawText(" /   |   |/  _ \\|  |  \\ \\   \\/\\/   /  |/    \\ |", COLOR_RED, levelCenter.x - x, levelCenter.y + y + 2);
	EngineDrawText(" \\____   (  <_> )  |  /  \\        /|  |   |  \\|", COLOR_RED, levelCenter.x - x, levelCenter.y + y + 3);
	EngineDrawText(" / ______|\\____/|____/    \\__/\\  / |__|___|  /_", COLOR_RED, levelCenter.x - x, levelCenter.y + y + 4);
	EngineDrawText(" \\/                            \\/          \\/\\/", COLOR_RED, levelCenter.x - x, levelCenter.y + y + 5);
	EngineDrawText("Press SPACEBAR to quit. ", COLOR_WHITE, levelCenter.x + 12, levelCenter.y + y + 9);

	if (EngineIsKeyPressed(' '))
	{
		EngineSetLevel(gEngineLevelQuit);
	}
}

// Free any memory associated with the Level2 game state.
void YouWinShutdown(void)
{
	ObjectManagerDestroyAllObjects();
	resetNumberOfEnemies();
}
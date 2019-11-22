//------------------------------------------------------------------------------
//
// File Name:	YouWin.h
// Author(s):	Frank Bartkus (frank.bartkus)
// Project:		Dungeon
// Course:		VGP2
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Function Declarations:
//------------------------------------------------------------------------------

// Initialize the memory associated with Menu.
void YouWinInit(void);

// Update the YouWin game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void YouWinUpdate(float dt);

// Free any memory associated with Menu.
void YouWinShutdown(void);
#pragma once

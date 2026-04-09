////////////////////////////////////////////////////////////////////////////////
///
/// @file		UserFunctions.hpp
/// @brief		File containing a namespace with declared functions that the user interacts with.
/// @details	This file contains a namespace with the declaration of functions that turn user input into output.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		UserFunctions.cpp
/// @see		Main.cpp
/// @see		UserFunctionsHelpers
///
////////////////////////////////////////////////////////////////////////////////
#pragma once

/// @brief   Namespace containing functions that the user interacts with.
/// @details Namespace containing functions that turn user input into output. It is the module
///			 that users directly interact with.
/// @author  Rajdeep Chowdhury
/// @date    8.04.2026
namespace UserFunctions {
	/// @brief   Allows the user to select their Sliding Tiles game difficulty.
	/// @details Prompts the user to select their @ref SlidingTilesEnums::Difficulty or to quit.
	///			 Selecting a difficulty will begin a game afterwards. Quitting will end program execution.
	/// @retval	 true If quit is not selected.
	/// @retval	 false If quit is selected.
	/// @author  Rajdeep Chowdhury
	/// @date    8.04.2026
	bool selectDifficulty();

	/// @brief   Allows the user to perform a slide in a Sliding Tiles game.
	/// @details Prompts the user to slide the empty tile in all @ref SlidingTilesEnums::Direction available
	///			 or to quit the game they are currently in. Sliding will affect the game state and end the game
	///			 if the win condition is met.
	/// @retval	 true If quit is not selected or the game is not over.
	/// @retval	 false If quit is selected
	/// @retval	 false If the game determines it can end.
	/// @author  Rajdeep Chowdhury
	/// @date    8.04.2026
	bool performSlide();
}
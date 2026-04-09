////////////////////////////////////////////////////////////////////////////////
///
/// @file		UserFunctionsHelpers.hpp
/// @brief		File containing a namespace of declared helper functions and a constant expression for @ref UserFunctions.
/// @details	This file contains a namespace of declared helper functions that the functions of @ref UserFunctions use.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		UserFunctionsHelpers.cpp
/// @see		UserFunctions
///
////////////////////////////////////////////////////////////////////////////////
#pragma once

//Forward declaration

namespace SlidingTilesEnums {
	enum class Direction;
}

/// @brief   Namespace containing helper functions used by @c UserFunctions.
/// @details Namespace containing helper functions that the functions of @ref UserFunctions use.
/// @author  Rajdeep Chowdhury
/// @date    8.04.2026
/// 
/// @see	 UserFunctions
namespace UserFunctionsHelpers {
	/// @brief   Initializes data to start a game of Sliding Tiles.
	/// @details Uses functions from @ref SlidingTilesFunctions to initialize the data required to start a game
	///			 of Sliding Tiles.
	/// @author  Rajdeep Chowdhury
	/// @date    8.04.2026
	void startGame();

	/// @brief		Tries to slide the empty tile in the given direction.
	/// @details	Tries to slide the empty tile in the given directionm handling both the success and failure cases.
	/// @param[in]	direction The direction the slide will occur.
	/// @author		Rajdeep Chowdhury
	/// @date		8.04.2026
	void trySlide(SlidingTilesEnums::Direction direction);

	/// @brief   Print the Sliding Tiles board.
	/// @details Displays all the tiles of the Sliding Tiles board onto the console.
	/// @author  Rajdeep Chowdhury
	/// @date    8.04.2026
	void printBoard();

	/// @brief   Print the Sliding Tiles leaderboard for the current difficulty.
	/// @details Displays the top @ref SlidingTilesFunctionsHelpers::LEADERBOARD_SIZE scores achieved for the
	///			 @ref SlidingTilesData::currentDifficulty being played.
	/// @author  Rajdeep Chowdhury
	/// @date    8.04.2026
	/// 
	/// @see	 SlidingTilesFunctionsHelpers
	/// @see	 SlidingTilesData
	void printLeaderboard();

	/// @brief   Determines whether the Sliding Tiles game should continue.
	/// @details Determines whether the Sliding Tiles game should continue based on if the board is ordered or not.
	///			 If the board is ordered, it will also handle applying the effect of winning the game.
	/// @retval	 true If the game must still continue.
	/// @retval	 false If the game should end.
	/// @author  Rajdeep Chowdhury
	/// @date    8.04.2026
	bool continueGame();
}
////////////////////////////////////////////////////////////////////////////////
///
/// @file		SlidingTilesFunctions.hpp
/// @brief		File containing a namespace with declared functions used during a game of Sliding Tiles.
/// @details	This file contains a namespace with the declaration of functions which are called during a 
///				game of Sliding Tiles to manipulate the data of @ref SlidingTilesData.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		SlidingTilesFunctions.cpp
/// @see		SlidingTilesData
///
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <vector>

//Forward declarations

namespace SlidingTilesEnums {
	enum class Difficulty;
	enum class Direction;
}

/// @brief   Namespace containing the functions used during a game of Sliding Tiles.
/// @details Namespace containing the functions which are called during a game of Sliding Tiles
///			 to change the properties of @ref SlidingTilesData.
/// @author  Rajdeep Chowdhury
/// @date    8.04.2026
/// 
/// @see	 SlidingTilesData
namespace SlidingTilesFunctions {
	/// @brief		Sets up the data required to start a Sliding Tiles game.
	/// @details	Reintializes the data in @ref SlidingTilesData to a reset state based on the 
	///				@p difficulty, allowing for a new game of Sliding Tiles to be played.
	/// @param[in]	difficulty The difficulty of the Sliding Tiles game being started.
	/// @author		Rajdeep Chowdhury
	/// @date		8.04.2026
	/// 
	/// @see		SlidingTilesData
	void startGame(SlidingTilesEnums::Difficulty difficulty);

	/// @brief		Attempts to slide the empty tile to an adjacent filled tile.
	/// @details	Attempts to swap the empty tile with an adjacent filled tile based on the 
	///				@p direction given. A slide will fail if the direction of slide given would 
	///				cause the empty tile to slide outside the board.
	/// @pre		@ref SlidingTilesData::board is not empty and all rows contain at least one element. 
	///				(i.e., the @ref Board::hasEmptyRow() call returns false.)
	/// @param[in]	direction The direction that the slide will occur.
	/// @retval		true If the slide succeeds.
	/// @retval		false If the slide fails.
	/// @retval		false If the pre-condition is not met.
	/// @author		Rajdeep Chowdhury
	/// @date		8.04.2026
	/// 
	/// @note		If the pre-condition is not met, the function returns early without attempting to modify the data.
	/// @note		This function does not increment @ref SlidingTilesData::slides. The caller is recommended to 
	///				increment it based on if this function is true.
	bool slide(SlidingTilesEnums::Direction direction);

	/// @brief	 Shuffles the board.
	/// @details Shuffles @ref SlidingTilesData::board by repeatedly calling @ref slide(SlidingTilesEnums::Direction)
	///			 with a random direction. The shuffle will not immediately backtrack, meaning it can't slide one direction
	///			 and then slide back the opposite direction immediately afterwards.
	/// @pre	 @ref SlidingTilesData::board is not empty and all rows contain at least one element.
	///			 (i.e., the @ref Board::hasEmptyRow() call returns false.)
	/// @author	 Fabio Bustamante Romillo
	/// @date	 8.04.2026
	/// 
	/// @note	 If the pre-condition is not met, the function returns early without modifying the data.
	/// @note	 The function @ref SlidingTilesFunctions::StartGame(SlidingTilesEnums::Difficulty) should be used before
	///			 calling this function.
	/// @warning If either one of the dimensions of the @ref SlidingTilesData::board is somehow equal to 1,
	///			 this function will enter an infinite loop due to its incapability to backtrack.
	///			 This should be impossible at the moment, but it is worth noting if this code is to be expanded on.
	/// 
	/// @see	 SlidingTilesFunctionsHelpers
	/// @see	 Board::hasEmptyRow()
	void shuffle();

	/// @brief   Checks if all the board's numbers are ordered.
	/// @details Checks if all the board's numbers are in their expected, ordered position, reading the board
	///			 from left to right and from top to bottom.
	/// @retval  true If the board is ordered.
	/// @retval	 false If the board is not ordered.
	/// @author  Fabio Bustamante Romillo
	/// @date    8.04.2026
	bool isBoardOrdered();

	/// @brief		Writes the number of slides to its associated leaderboard.
	/// @details	Appends the current number of @ref SlidingTilesData::slides to the end of a text file 
	///				representing the leaderboard of the given @p difficulty.
	/// @param[in]	difficulty The difficulty of the Sliding Tiles game being played.
	/// @author		Raj Bahadur Bhat
	/// @date		8.04.2026
	/// 
	/// @note		The amount of scores that can be in a leaderboard text file has no limit.
	void writeScore(SlidingTilesEnums::Difficulty difficulty);

	/// @brief		Loads the top scores from its associated leaderboard.
	/// @details	Loads all scores from a text file representing the leaderboard of the given @p difficulty 
	///				into a vector, sorts them in ascneding order, then filters the scores to the top
	///				@ref SlidingTilesFunctionsHelpers::LEADERBOARD_SIZE scores.
	/// @param[in]	difficulty The difficulty of the Sliding Tiles game leaderboard.
	/// @return		A vector of the top scores.
	/// @author		Raj Bahadur Bhat
	/// @date		8.04.2026
	/// 
	/// @see		SlidingTilesFunctionsHelpers::LEADERBOARD_SIZE
	std::vector<unsigned int> loadScores(SlidingTilesEnums::Difficulty difficulty);
}
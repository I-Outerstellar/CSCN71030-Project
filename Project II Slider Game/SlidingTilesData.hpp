////////////////////////////////////////////////////////////////////////////////
///
/// @file		SlidingTilesData.hpp
/// @brief		File containing a namespace data for a Sliding Tiles game.
/// @details	This file contains a namespace with external links to data that change and persist 
///				during a Sliding Tiles game.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		SlidingTilesData.cpp
///
////////////////////////////////////////////////////////////////////////////////
#pragma once

//Forward declarations

class Board;

namespace SlidingTilesEnums {
	enum class Difficulty; 
}

/// @brief   Namespace containing data for a Sliding Tiles game.
/// @details Namespace containing data that changes and persists between functions during a
///			 game of Sliding Tiles.
/// @author  Rajdeep Chowdhury
/// @date    8.04.2026
namespace SlidingTilesData {
	/// @brief The @c Board object for Sliding Tiles.
	/// @details The @c Board object which is used during a Sliding Tiles game.
	extern Board board;

	/// @brief The amount of slides performed.
	/// @details The amount of slides which occur during a Sliding Tiles game.
	extern unsigned int slides;

	/// @brief The current row index of the empty tile.
	/// @details The row index of the empty tile of the Sliding Tiles game.
	extern size_t currentRow; 

	/// @brief The current column index of the empty tile.
	/// @details The column index of the empty tile of the Sliding Tiles game.
	extern size_t currentColumn;

	/// @brief The size of the board in a single direction.
	/// @details The amount of tiles the board has in a single direction.
	extern size_t boardSize;

	/// @brief The current difficulty being played.
	/// @details The difficulty of the Sliding Tiles game being played.
	extern SlidingTilesEnums::Difficulty currentDifficulty;
}


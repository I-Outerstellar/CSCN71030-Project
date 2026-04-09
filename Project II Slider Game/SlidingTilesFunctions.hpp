////////////////////////////////////////////////////////////////////////////////
///
/// @file		SlidingTilesFunctions.hpp
/// @brief     
/// @details	~
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		SlidingTilesFunctions.cpp
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
	/// @brief		
	/// @details	~
	/// @param[in]	difficulty
	/// @author		Rajdeep Chowdhury
	/// @date		8.04.2026
	void startGame(SlidingTilesEnums::Difficulty difficulty);

	/// @brief		
	/// @details	~
	/// @param[in]	direction
	/// @return		
	/// @author		Rajdeep Chowdhury
	/// @date		8.04.2026
	bool slide(SlidingTilesEnums::Direction direction);

	/// @brief   
	/// @details ~
	/// @author  Fabio Bustamante Romillo
	/// @date    8.04.2026
	void shuffle();

	/// @brief   
	/// @details ~
	/// @retval  true If the board is ordered.
	/// @retval	 false If the board is not ordered.
	/// @author  Fabio Bustamante Romillo
	/// @date    8.04.2026
	bool isBoardOrdered();

	/// @brief		
	/// @details	~
	/// @param[in]	difficulty
	/// @author		Raj Bahadur Bhat
	/// @date		8.04.2026
	void writeScore(SlidingTilesEnums::Difficulty difficulty);

	/// @brief		
	/// @details	~
	/// @param[in]	difficulty
	/// @return		
	/// @author		Raj Bahadur Bhat
	/// @date		8.04.2026
	std::vector<unsigned int> loadScores(SlidingTilesEnums::Difficulty difficulty);
}
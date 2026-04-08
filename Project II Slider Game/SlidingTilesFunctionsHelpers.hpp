////////////////////////////////////////////////////////////////////////////////
///
/// @file		SlidingTilesFunctionsHelpers.hpp
/// @brief		File containing namespace of declared helper functions and a constant expression for @ref SlidingTilesFunctions.
/// @details	This file contains a namespace of declared helper functions and a @c constexpr integer that the functions of 
///				@ref SlidingTilesFunctions use.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		SlidingTilesFunctionsHelpers.cpp
/// @see		SlidingTilesFunctions
///
////////////////////////////////////////////////////////////////////////////////
#pragma once

//Forward declaration
namespace SlidingTilesEnums {
	enum class Direction;
}

/// @brief   Namespace containing helper functions and a constant expression used by @ref SlidingTilesFunctions.
/// @details namespace of helper functions and a @c constexpr integer that the functions of
///			 @ref SlidingTilesFunctions use.
/// @author  Rajdeep Chowdhury
/// @date    8.04.2026
/// 
/// @see	SlidingTilesFunctions
namespace SlidingTilesFunctionsHelpers {
	/// @brief Constant representing the size of the leaderboard.
	/// @details Constant integer representing how many scores are loaded by the leaderboard.
	constexpr unsigned short LEADERBOARD_SIZE = 10;

	/// @brief   Generates a random direction
	/// @details Generates a random @ref SlidingTilesEnums::Direction
	/// @retval	 SlidingTilesEnums::Direction::UP 1/4 chance.
	/// @retval	 SlidingTilesEnums::Direction::DOWN 1/4 chance.
	/// @retval	 SlidingTilesEnums::Direction::LEFT 1/4 chance.
	/// @retval	 SlidingTilesEnums::Direction::RIGHT 1/4 chance.
	/// @author  Fabio Bustamante Romillo
	/// @date    8.04.2026
	SlidingTilesEnums::Direction getRandomDirection();

	/// @brief		Converts the direction given into its opposite direction.
	/// @details	Converts @p dir into the @ref SlidingTilesEnums::Direction representation of the
	///				logical/common-sense opposite direction.
	/// @param[in]	dir	The direction which will be converted.
	/// @retval		SlidingTilesEnums::Direction::UP If the direction given is @c SlidingTilesEnums::Direction::DOWN
	/// @retval		SlidingTilesEnums::Direction::DOWN If the direction given is @c SlidingTilesEnums::Direction::UP
	/// @retval		SlidingTilesEnums::Direction::LEFT If the direction given is @c SlidingTilesEnums::Direction::RIGHT
	/// @retval		SlidingTilesEnums::Direction::RIGHT If the direction given is @c SlidingTilesEnums::Direction::LEFT
	/// @author		Fabio Bustamante Romillo
	/// @date		8.04.2026
	SlidingTilesEnums::Direction getOpposite(SlidingTilesEnums::Direction dir);
}
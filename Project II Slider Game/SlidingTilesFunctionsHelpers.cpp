////////////////////////////////////////////////////////////////////////////////
///
/// @file		SlidingTilesFunctionsHelpers.cpp
/// @brief		File containing the initialization of the @ref SlidingTilesFunctionsHelpers functions.
/// @details	This file contains the initialization of the @ref SlidingTilesFunctionsHelpers helper functions 
///				declared in @ref SlidingTilesFunctionsHelpers.hpp.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		SlidingTilesFunctionsHelpers.hpp
/// @see		SlidingTilesEnums.hpp
/// @see		SlidingTilesFunctions
///
////////////////////////////////////////////////////////////////////////////////
#include "SlidingTilesFunctionsHelpers.hpp"
#include "SlidingTilesEnums.hpp"
#include <algorithm>

namespace SlidingTilesFunctionsHelpers {
	SlidingTilesEnums::Direction getRandomDirection() {
		int r = std::rand() % 4;
		return static_cast<SlidingTilesEnums::Direction>(r);
	}

	SlidingTilesEnums::Direction getOpposite(SlidingTilesEnums::Direction dir) {
		switch (dir) {
		case SlidingTilesEnums::Direction::UP:    return SlidingTilesEnums::Direction::DOWN;
		case SlidingTilesEnums::Direction::DOWN:  return SlidingTilesEnums::Direction::UP;
		case SlidingTilesEnums::Direction::LEFT:  return SlidingTilesEnums::Direction::RIGHT;
		case SlidingTilesEnums::Direction::RIGHT: return SlidingTilesEnums::Direction::LEFT;
		}
		return SlidingTilesEnums::Direction::UP; // fallback
	}
}
////////////////////////////////////////////////////////////////////////////////
///
/// @file		SlidingTilesData.cpp
/// @brief		File containing sliding tiles variable initializations.
/// @details	This file contains the initializations of the externally linked
///				@ref SlidingTilesData namespace varaibles.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		SlidingTilesData.hpp
/// @see		SlidingTilesData
///
////////////////////////////////////////////////////////////////////////////////
#include "Board.hpp"
#include "SlidingTilesData.hpp"
#include "SlidingTilesEnums.hpp"

namespace SlidingTilesData {
	Board board;
	unsigned int slides = 0;
	size_t currentRow = 0, currentColumn = 0;
	size_t boardSize = 0;
	SlidingTilesEnums::Difficulty currentDifficulty = SlidingTilesEnums::Difficulty::EASY;
}
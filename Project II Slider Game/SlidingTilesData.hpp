#pragma once
#include "Board.hpp"

namespace SlidingTilesEnums {
	enum class Difficulty;
}

namespace SlidingTilesData {
	extern Board board;
	extern unsigned int slides;
	extern size_t currentRow, currentColumn; //The current row and column of the empty square
	extern size_t boardSize;
	extern SlidingTilesEnums::Difficulty currentDifficulty;
}


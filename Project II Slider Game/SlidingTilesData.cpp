#include "SlidingTilesData.hpp"
#include "SlidingTilesEnums.hpp"

namespace SlidingTilesData {
	Board board;
	unsigned int slides = 0;
	size_t currentRow = 0, currentColumn = 0;
	size_t boardSize = 0;
	SlidingTilesEnums::Difficulty currentDifficulty = SlidingTilesEnums::Difficulty::EASY;
}
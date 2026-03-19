#pragma once
#include <vector>
#include "Board.hpp"
#include "SlidingTilesEnums.hpp"

namespace SlidingTilesFunctions {
	void startGame(SlidingTilesEnums::Difficulty difficulty);

	bool slide(Board& board, SlidingTilesEnums::Direction direction);

	void shuffle(Board& board);

	bool isBoardOrdered(Board& board);

	void writeScore(SlidingTilesEnums::Difficulty difficulty);

	std::vector<unsigned int> loadScores(SlidingTilesEnums::Difficulty difficulty);
}
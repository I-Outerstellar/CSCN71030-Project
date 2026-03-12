#pragma once
#include <vector>
#include "Board.hpp"
#include "SlidingTilesEnums.hpp"

namespace SlidingTilesFunctions {
	void startGame(SlidingTilesEnums::Difficulty difficulty);

	bool slide(Board& board, int tile);

	void shuffle(Board& board);

	bool isBoardOrdered(Board& board);

	void writeScore();

	void loadScores();
}
#pragma once
#include <vector>
#include "Board.hpp"
#include "SlidingTilesEnums.hpp"

namespace SlidingTilesFunctions {
	void startGame(SlidingTilesEnums::Difficulty difficulty);

	bool slide(SlidingTilesEnums::Direction direction);

	void shuffle();

	bool isBoardOrdered();

	void writeScore();

	void loadScores();
}
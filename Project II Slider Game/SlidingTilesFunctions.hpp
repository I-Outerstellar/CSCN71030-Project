#pragma once
#include <vector>
#include "Board.hpp"

//Forward declaration
namespace SlidingTilesEnums {
	enum class Difficulty;
	enum class Direction;
}

namespace SlidingTilesFunctions {
	void startGame(SlidingTilesEnums::Difficulty difficulty);

	bool slide(SlidingTilesEnums::Direction direction);

	void shuffle();

	bool isBoardOrdered();

	void writeScore(SlidingTilesEnums::Difficulty difficulty);

	std::vector<unsigned int> loadScores(SlidingTilesEnums::Difficulty difficulty);
}
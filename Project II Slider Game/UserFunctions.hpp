#pragma once
#include "SlidingTilesEnums.hpp"

namespace UserFunctions {
	SlidingTilesEnums::Difficulty selectDifficulty();

	SlidingTilesEnums::Direction getValidDirection();

	bool getPlayAgain();
}
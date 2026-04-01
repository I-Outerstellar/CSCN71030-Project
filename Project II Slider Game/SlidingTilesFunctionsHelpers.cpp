#include "SlidingTilesFunctionsHelpers.hpp"

namespace SlidingTilesFunctionsHelpers {
	constexpr unsigned short LEADERBOARD_SIZE = 10;

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
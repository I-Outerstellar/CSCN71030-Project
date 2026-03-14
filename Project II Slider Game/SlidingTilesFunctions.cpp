#include "SlidingTilesFunctions.hpp"
#include "SlidingTilesData.hpp"

namespace SlidingTilesFunctions {

	bool slide(Board& board, SlidingTilesEnums::Direction direction) { 
		using namespace SlidingTilesData;
		bool canSlide = false;

		//Determine if a slide can occur in the desired direction
		switch (direction) {
		case SlidingTilesEnums::Direction::DOWN:
			canSlide = board.canAccess(currentColumn + 1, currentRow);
			break;
		case SlidingTilesEnums::Direction::UP:
			canSlide = board.canAccess(currentColumn - 1, currentRow);
			break;
		case SlidingTilesEnums::Direction::LEFT:
			canSlide = board.canAccess(currentColumn, currentRow - 1);
			break;
		case SlidingTilesEnums::Direction::RIGHT:
			canSlide = board.canAccess(currentColumn, currentRow + 1);
			break;
		}

		if (!canSlide) return false;

		//Slide the desired square to the empty square
		switch (direction) {
		case SlidingTilesEnums::Direction::DOWN:
			std::swap(board.access(currentColumn, currentRow), board.access(currentColumn + 1, currentRow));
			currentColumn += 1;
			break;
		case SlidingTilesEnums::Direction::UP:
			std::swap(board.access(currentColumn, currentRow), board.access(currentColumn - 1, currentRow));
			currentColumn -= 1;
			break;
		case SlidingTilesEnums::Direction::LEFT:
			std::swap(board.access(currentColumn, currentRow), board.access(currentColumn, currentRow - 1));
			currentRow -= 1;
			break;
		case SlidingTilesEnums::Direction::RIGHT:
			std::swap(board.access(currentColumn, currentRow), board.access(currentColumn, currentRow + 1));
			currentRow += 1;
			break;
		}
		return true;
	}

}
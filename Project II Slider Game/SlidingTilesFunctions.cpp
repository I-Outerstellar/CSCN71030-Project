#include "SlidingTilesFunctions.hpp"
#include "SlidingTilesData.hpp"

namespace SlidingTilesFunctions {

	void startGame(SlidingTilesEnums::Difficulty difficulty) {
		SlidingTilesData::board = Board(difficulty);
		SlidingTilesData::boardSize = static_cast<int>(difficulty);
		SlidingTilesData::currentColumn =
			SlidingTilesData::currentRow =
			SlidingTilesData::boardSize - 1;
		SlidingTilesData::slides = 0;
	}

	bool slide(SlidingTilesEnums::Direction direction) { 
		using namespace SlidingTilesData;
		bool canSlide = false;
		//if (board.hasEmptyRow()) return false;

		//Determine if a slide can occur in the desired direction
		switch (direction) {
		case SlidingTilesEnums::Direction::DOWN:
			canSlide = board.canAccess(currentRow + 1, currentColumn);
			break;
		case SlidingTilesEnums::Direction::UP:
			canSlide = board.canAccess(currentRow - 1, currentColumn);
			break;
		case SlidingTilesEnums::Direction::LEFT:
			canSlide = board.canAccess(currentRow, currentColumn - 1);
			break;
		case SlidingTilesEnums::Direction::RIGHT:
			canSlide = board.canAccess(currentRow, currentColumn + 1);
			break;
		}

		if (!canSlide) return false;

		//Slide the desired square to the empty square
		switch (direction) {
		case SlidingTilesEnums::Direction::DOWN:
			std::swap(board.access(currentRow, currentColumn), board.access(currentRow + 1, currentColumn));
			currentRow += 1;
			break;
		case SlidingTilesEnums::Direction::UP:
			std::swap(board.access(currentRow, currentColumn), board.access(currentRow - 1, currentColumn));
			currentRow -= 1;
			break;
		case SlidingTilesEnums::Direction::LEFT:
			std::swap(board.access(currentRow, currentColumn), board.access(currentRow, currentColumn - 1));
			currentColumn -= 1;
			break;
		case SlidingTilesEnums::Direction::RIGHT:
			std::swap(board.access(currentRow, currentColumn), board.access(currentRow, currentColumn + 1));
			currentColumn += 1;
			break;
		}
		return true;
	}

}
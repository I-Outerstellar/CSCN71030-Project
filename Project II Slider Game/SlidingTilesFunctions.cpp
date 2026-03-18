#include "SlidingTilesFunctions.hpp"
#include "SlidingTilesData.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

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
		if (board.hasEmptyRow()) return false;

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

	void shuffle() {
		std::srand(static_cast<unsigned int>(std::time(nullptr)));

		int moves = SlidingTilesData::boardSize * SlidingTilesData::boardSize * 10;

		SlidingTilesEnums::Direction lastMove;
		bool hasLastMove = false;

		for (int i = 0; i < moves; i++) {
			SlidingTilesEnums::Direction move;
			bool validMove = false;

			while (!validMove) {
				move = getRandomDirection();

				int newRow = static_cast<int>(SlidingTilesData::currentRow);
				int newCol = static_cast<int>(SlidingTilesData::currentColumn);

				switch (move) {
				case SlidingTilesEnums::Direction::UP:    newRow--; break;
				case SlidingTilesEnums::Direction::DOWN:  newRow++; break;
				case SlidingTilesEnums::Direction::LEFT:  newCol--; break;
				case SlidingTilesEnums::Direction::RIGHT: newCol++; break;
				}

				bool canMove = SlidingTilesData::board.canAccess(newRow, newCol);
				bool notOpposite = !hasLastMove || move != getOpposite(lastMove);

				validMove = canMove && notOpposite;
			}

			slide(move);
			lastMove = move;
			hasLastMove = true;
		}

		// Move empty tile to bottom right
		while (SlidingTilesData::currentRow < SlidingTilesData::boardSize - 1)
			slide(SlidingTilesEnums::Direction::DOWN);
		while (SlidingTilesData::currentColumn < SlidingTilesData::boardSize - 1)
			slide(SlidingTilesEnums::Direction::RIGHT);
	}

}
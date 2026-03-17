#include "SlidingTilesFunctions.hpp"
#include "SlidingTilesData.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
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
		using namespace SlidingTilesData;

		std::srand(static_cast<unsigned int>(std::time(nullptr)));

		// Number of moves based on difficulty
		int moves = boardSize * boardSize * 10;

		SlidingTilesEnums::Direction lastMove;
		bool hasLastMove = false;

		for (int i = 0; i < moves; i++) {
			std::vector<SlidingTilesEnums::Direction> possibleMoves;

			// Check all valid directions
			if (board.canAccess(currentRow + 1, currentColumn))
				possibleMoves.push_back(SlidingTilesEnums::Direction::DOWN);

			if (board.canAccess(currentRow - 1, currentColumn))
				possibleMoves.push_back(SlidingTilesEnums::Direction::UP);

			if (board.canAccess(currentRow, currentColumn + 1))
				possibleMoves.push_back(SlidingTilesEnums::Direction::RIGHT);

			if (board.canAccess(currentRow, currentColumn - 1))
				possibleMoves.push_back(SlidingTilesEnums::Direction::LEFT);

			// Remove opposite of last move (to avoid backtracking)
			if (hasLastMove) {
				for (int j = 0; j < possibleMoves.size(); j++) {
					bool isOpposite = false;

					if (lastMove == SlidingTilesEnums::Direction::UP &&
						possibleMoves[j] == SlidingTilesEnums::Direction::DOWN) isOpposite = true;

					if (lastMove == SlidingTilesEnums::Direction::DOWN &&
						possibleMoves[j] == SlidingTilesEnums::Direction::UP) isOpposite = true;

					if (lastMove == SlidingTilesEnums::Direction::LEFT &&
						possibleMoves[j] == SlidingTilesEnums::Direction::RIGHT) isOpposite = true;

					if (lastMove == SlidingTilesEnums::Direction::RIGHT &&
						possibleMoves[j] == SlidingTilesEnums::Direction::LEFT) isOpposite = true;

					if (isOpposite) {
						possibleMoves.erase(possibleMoves.begin() + j);
						break;
					}
				}
			}

			// Pick random move
			int randIndex = std::rand() % possibleMoves.size();
			SlidingTilesEnums::Direction move = possibleMoves[randIndex];

			// Perform move
			slide(move);

			// Store last move
			lastMove = move;
			hasLastMove = true;
		}

		// Reset player moves after shuffle
		slides = 0;
	}
}
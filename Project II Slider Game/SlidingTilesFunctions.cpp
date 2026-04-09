#include "SlidingTilesFunctions.hpp"
#include "SlidingTilesFunctionsHelpers.hpp"
#include "SlidingTilesData.hpp"
#include "SlidingTilesEnums.hpp"
#include "Board.hpp"
#include <vector>
#include <fstream>
#include <algorithm>

namespace SlidingTilesFunctions {

	void startGame(SlidingTilesEnums::Difficulty difficulty) {
		SlidingTilesData::board = Board(difficulty);
		SlidingTilesData::boardSize = static_cast<int>(difficulty);
		SlidingTilesData::currentColumn =
			SlidingTilesData::currentRow =
			SlidingTilesData::boardSize - 1;
		SlidingTilesData::slides = 0;
		SlidingTilesData::currentDifficulty = difficulty;
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

		size_t moves = SlidingTilesData::boardSize * SlidingTilesData::boardSize * 10;

		SlidingTilesEnums::Direction lastMove = SlidingTilesEnums::Direction::UP;
		bool hasLastMove = false;
		int i = 0;
		while (i < moves) {
			SlidingTilesEnums::Direction move = SlidingTilesFunctionsHelpers::getRandomDirection();

			// validMove = true only if move is not opposite and slide succeeds
			bool validMove = (!hasLastMove || move != SlidingTilesFunctionsHelpers::getOpposite(lastMove)) && slide(move);

			// increment counter if valid
			i += validMove;                           // true = 1, false = 0
			lastMove = validMove ? move : lastMove;   // update lastMove only if valid
			hasLastMove = hasLastMove || validMove;   // mark hasLastMove if any move succeeded
		}

		// Move empty tile to bottom right
		while (SlidingTilesData::currentRow < SlidingTilesData::boardSize - 1)
			slide(SlidingTilesEnums::Direction::DOWN);
		while (SlidingTilesData::currentColumn < SlidingTilesData::boardSize - 1)
			slide(SlidingTilesEnums::Direction::RIGHT);
	}

	bool isBoardOrdered() {
		bool isOrdered = true;

		for (size_t row = 0; row < SlidingTilesData::boardSize; row++) {
			for (size_t col = 0; col < SlidingTilesData::boardSize; col++) {

				size_t expectedValue = row * SlidingTilesData::boardSize + col + 1;

				isOrdered = isOrdered && (SlidingTilesData::board.access(row, col) == expectedValue);
			}
		}

		return isOrdered;
	}

	void writeScore(SlidingTilesEnums::Difficulty difficulty) {
		// Get filename based on difficulty
		std::string filename;
		switch (difficulty) {
		case SlidingTilesEnums::Difficulty::EASY:
			filename = "scores_easy.txt";
			break;
		case SlidingTilesEnums::Difficulty::MEDIUM:
			filename = "scores_medium.txt";
			break;
		case SlidingTilesEnums::Difficulty::HARD:
			filename = "scores_hard.txt";
			break;
		case SlidingTilesEnums::Difficulty::INSANE:
			filename = "scores_insane.txt";
			break;
		}

		// Open file to append score
		std::ofstream outFile(filename, std::ios::app);
		if (outFile.is_open()) {
			outFile << SlidingTilesData::slides << std::endl;
			outFile.close();
		}
	}

	std::vector<unsigned int> loadScores(SlidingTilesEnums::Difficulty difficulty) {
		std::vector<unsigned int> scores;

		// Get filename based on difficulty
		std::string filename;
		switch (difficulty) {
		case SlidingTilesEnums::Difficulty::EASY:
			filename = "scores_easy.txt";
			break;
		case SlidingTilesEnums::Difficulty::MEDIUM:
			filename = "scores_medium.txt";
			break;
		case SlidingTilesEnums::Difficulty::HARD:
			filename = "scores_hard.txt";
			break;
		case SlidingTilesEnums::Difficulty::INSANE:
			filename = "scores_insane.txt";
			break;
		}

		// Read all scores from file
		std::ifstream inFile(filename);
		if (inFile.is_open()) {
			unsigned int score;
			while (inFile >> score) {
				scores.push_back(score);
			}
			inFile.close();
		}

		// Sort scores (lowest is best)
		std::sort(scores.begin(), scores.end());

		// Keep only top 10
		if (scores.size() > SlidingTilesFunctionsHelpers::LEADERBOARD_SIZE) {
			scores.resize(SlidingTilesFunctionsHelpers::LEADERBOARD_SIZE);
		}

		return scores;
	}
}
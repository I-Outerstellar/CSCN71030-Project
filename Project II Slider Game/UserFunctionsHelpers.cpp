////////////////////////////////////////////////////////////////////////////////
///
/// @file      UserFunctionsHelpers.cpp
/// @brief     
/// @details   ~
/// @author    Rajdeep Chowdhury
/// @date      8.04.2026
///
////////////////////////////////////////////////////////////////////////////////
#include "UserFunctionsHelpers.hpp"
#include "SlidingTilesFunctions.hpp"
#include "SlidingTilesData.hpp"
#include "SlidingTilesEnums.hpp"
#include <iostream>

namespace UserFunctionsHelpers {
	void startGame() {
		printLeaderboard();
		SlidingTilesFunctions::startGame(SlidingTilesData::currentDifficulty);
		SlidingTilesFunctions::shuffle();
	}

	void trySlide(SlidingTilesEnums::Direction direction) {
		//Perform diffefrent results depending on if the slide succeeds or not
		bool success = SlidingTilesFunctions::slide(direction);
		if (success) SlidingTilesData::slides++;
		else std::cout << "No tile found in that direction." << std::endl;
	}

	void printBoard() {
		//Use a nested for loop
		for (int i = 0; i < SlidingTilesData::boardSize; i++) {
			if (!SlidingTilesData::board.canAccess(i)) break; //For safety
			for (size_t tile : SlidingTilesData::board.access(i)) {
				if (tile == SlidingTilesData::boardSize * SlidingTilesData::boardSize) std::cout << "[  ]";
				else if (tile <= 9) std::cout << "[ " << tile << ']';
				else std::cout << '[' << tile << ']';
			}
			std::cout << '\n';
		}
	}

	void printLeaderboard() {
		//Load top scores then print them
		std::vector<unsigned int> scores = SlidingTilesFunctions::loadScores(SlidingTilesData::currentDifficulty);
		std::cout << "\nLEADERBOARD\n";
		for (int i = 0; i < scores.size(); i++) {
			std::cout << i + 1 << ". " << scores.at(i) << '\n';
		}
		std::cout << '\n';
	}

	bool continueGame() {
		using namespace SlidingTilesData;
		//The last move of the sliding tiles game is always making the empty tile go to the bottom right corner
		if (board.access(boardSize - 1, boardSize - 1) != boardSize * boardSize) return true;
		//Then check if the board is ordered to trigger a win
		else if (SlidingTilesFunctions::isBoardOrdered()) {
			SlidingTilesFunctions::writeScore(currentDifficulty);
			printBoard();
			std::cout << "Winner! \n";
			printLeaderboard();
			return false;
		}
		else return true;
	}

}
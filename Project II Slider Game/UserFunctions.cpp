#include "UserFunctions.hpp"
#include "SlidingTilesFunctions.hpp"
#include "SlidingTilesData.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

namespace {
	void startGame() {
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
			std::cout << i+1 << ". " << scores.at(i) << '\n';
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

namespace UserFunctions {
	bool selectDifficulty() {
		//Infinute loop to ensure a valid option is picked
		while (true) {
			//Get and transform user input
			std::string input;
			std::cout << "SELECT:  [Easy]  [Medium]  [Hard]  [Insane]  [Quit]\n" << std::endl;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(),
				[](unsigned char character) { return std::tolower(character); });

			//Check if it is one of the options;
			if (input == "easy" || input == "e") {
				SlidingTilesData::currentDifficulty = SlidingTilesEnums::Difficulty::EASY;
				startGame();
				return true;
			}
			else if (input == "medium" || input == "m") {
				SlidingTilesData::currentDifficulty = SlidingTilesEnums::Difficulty::MEDIUM;
				startGame();
				return true;
			}
			else if (input == "hard" || input == "h") {
				SlidingTilesData::currentDifficulty = SlidingTilesEnums::Difficulty::HARD;
				startGame();
				return true;
			}
			else if (input == "insane" || input == "i") {
				SlidingTilesData::currentDifficulty = SlidingTilesEnums::Difficulty::INSANE;
				startGame();
				return true;
			}
			else if (input == "quit" || input == "q") {
				return false;
			}
			else std::cout << "Invalid option" << std::endl;
		}
	}

	bool performSlide() {
		//Infinute loop to ensure a valid option is picked
		while (true) {
			printBoard();

			//Get and transform user inpupt
			std::string input;
			std::cout << "SELECT:  [LEFT/A]  [RIGHT/D]  [UP/W]  [DOWN/S]  [Quit]\n" << std::endl;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(),
				[](unsigned char character) { return std::tolower(character); });

			//Check if it matches one of the options
			if (input == "left" || input == "a") {
				trySlide(SlidingTilesEnums::Direction::LEFT);
				return continueGame();
			}
			else if (input == "right" || input == "d") {
				trySlide(SlidingTilesEnums::Direction::RIGHT);
				return continueGame();
			}
			else if (input == "up" || input == "w") {
				trySlide(SlidingTilesEnums::Direction::UP);
				return continueGame();
			}
			else if (input == "down" || input == "s") {
				trySlide(SlidingTilesEnums::Direction::DOWN);
				return continueGame();
			}
			else if (input == "quit") {
				return false;
			}
			else std::cout << "Invalid option" << std::endl;
		}
	}
}
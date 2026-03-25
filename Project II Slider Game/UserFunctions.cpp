#include "UserFunctions.hpp"
#include "SlidingTilesFunctions.hpp"
#include "SlidingTilesData.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

namespace {
	void printBoard() {
		for (int i = 0; i < SlidingTilesData::boardSize; i++) {
			if (!SlidingTilesData::board.canAccess(i)) break;
			for (size_t tile : SlidingTilesData::board.access(i)) {
				if (tile == SlidingTilesData::boardSize * SlidingTilesData::boardSize) std::cout << "[  ]";
				else if (tile < 10) std::cout << "[0" << tile << ']';
				else std::cout << '[' << tile << ']';
			}
			std::cout << '\n';
		}
	}

	bool continueGame() {
		return false;
	}
}

namespace UserFunctions {
	bool selectDifficulty() {
		//Infinute loop to ensure a valid option is picked
		while (true) {

			//Get and transform user input
			std::string input;
			std::cout << "SELECT:\t[Easy]\t[Medium]\t[Hard]\t[Insane]\t[Quit]\n" << std::endl;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(),
				[](unsigned char character) { return std::tolower(character); });

			//Check if it is one of the options;
			if (input == "easy") {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::EASY);
				SlidingTilesFunctions::shuffle();
				return true;
			}
			else if (input == "medium") {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::MEDIUM);
				SlidingTilesFunctions::shuffle();
				return true;
			}
			else if (input == "hard") {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::HARD);
				SlidingTilesFunctions::shuffle();
				return true;
			}
			else if (input == "insane") {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::INSANE);
				SlidingTilesFunctions::shuffle();
				return true;
			}
			else if (input == "quit") {
				return false;
			}
			else std::cout << "Invalid option" << std::endl;
		}
	}

	bool getValidDirection() {
		//Infinute loop to ensure a valid option is picked
		while (true) {
			printBoard();

			//Get and transform user inpupt
			std::string input;
			std::cout << "SELECT:\t[LEFT]\t[RIGHT]\t[UP]\t[DOWN]\t[Quit]\n" << std::endl;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(),
				[](unsigned char character) { return std::tolower(character); });

			//Check if it matches one of the options
			//The directions are reversed as the user will see numbered tiles sliding to the empty space,
			//rather than the empty tile sliding to a filled space
			if (input == "left") {
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::RIGHT);
				return continueGame();
			}
			else if (input == "right") {
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::LEFT);
				return continueGame();
			}
			else if (input == "up") {
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::DOWN;
				return continueGame();
			}
			else if (input == "down") {
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::UP);
				return continueGame();
			}
			else if (input == "quit") {
				return false;
			}
			else std::cout << "Invalid option" << std::endl;
		}
	}
}
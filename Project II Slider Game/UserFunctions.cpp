#include "UserFunctions.hpp"
#include "UserFunctionsHelpers.hpp"
#include "SlidingTilesFunctions.hpp"
#include "SlidingTilesData.hpp"
#include <string>
#include <iostream>
#include <algorithm>

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
				UserFunctionsHelpers::startGame();
				return true;
			}
			else if (input == "medium" || input == "m") {
				SlidingTilesData::currentDifficulty = SlidingTilesEnums::Difficulty::MEDIUM;
				UserFunctionsHelpers::startGame();
				return true;
			}
			else if (input == "hard" || input == "h") {
				SlidingTilesData::currentDifficulty = SlidingTilesEnums::Difficulty::HARD;
				UserFunctionsHelpers::startGame();
				return true;
			}
			else if (input == "insane" || input == "i") {
				SlidingTilesData::currentDifficulty = SlidingTilesEnums::Difficulty::INSANE;
				UserFunctionsHelpers::startGame();
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
			UserFunctionsHelpers::printBoard();

			//Get and transform user inpupt
			std::string input;
			std::cout << "SELECT:  [LEFT/A]  [RIGHT/D]  [UP/W]  [DOWN/S]  [Quit]\n" << std::endl;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(),
				[](unsigned char character) { return std::tolower(character); });

			//Check if it matches one of the options
			if (input == "left" || input == "a") {
				UserFunctionsHelpers::trySlide(SlidingTilesEnums::Direction::LEFT);
				return UserFunctionsHelpers::continueGame();
			}
			else if (input == "right" || input == "d") {
				UserFunctionsHelpers::trySlide(SlidingTilesEnums::Direction::RIGHT);
				return UserFunctionsHelpers::continueGame();
			}
			else if (input == "up" || input == "w") {
				UserFunctionsHelpers::trySlide(SlidingTilesEnums::Direction::UP);
				return UserFunctionsHelpers::continueGame();
			}
			else if (input == "down" || input == "s") {
				UserFunctionsHelpers::trySlide(SlidingTilesEnums::Direction::DOWN);
				return UserFunctionsHelpers::continueGame();
			}
			else if (input == "quit") {
				return false;
			}
			else std::cout << "Invalid option" << std::endl;
		}
	}
}
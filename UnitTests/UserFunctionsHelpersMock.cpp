#include "UserFunctionsHelpersMock.hpp"
#include "SlidingTilesFunctionsMock.hpp"
#include "../Project II Slider Game/SlidingTilesData.hpp"
#include "../Project II Slider Game/SlidingTilesFunctions.hpp"
#include "../Project II Slider Game/Board.hpp"

namespace UserFunctionsHelpersMock {
	void trySlide(SlidingTilesEnums::Direction direction) {
		//Perform diffefrent results depending on if the slide succeeds or not
		bool success = SlidingTilesFunctions::slide(direction);
		if (success) SlidingTilesData::slides++;
	}

	bool continueGame(std::string fileName) {
		using namespace SlidingTilesData;
		//The last move of the sliding tiles game is always making the empty tile go to the bottom right corner
		if (board.access(boardSize - 1, boardSize - 1) != boardSize * boardSize) return true;
		//Then check if the board is ordered to trigger a win
		else if (SlidingTilesFunctions::isBoardOrdered()) {
			SlidingTilesFunctionsMock::writeScore(fileName);
			return false;
		}
		else return true;
	}
}
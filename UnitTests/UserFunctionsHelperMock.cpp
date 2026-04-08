#include "UserFunctionsHelperMock.hpp"
#include "../Project II Slider Game/SlidingTilesData.hpp"
#include "../Project II Slider Game/SlidingTilesFunctions.hpp"

namespace UserFunctionsHelperMock {
	bool continueGame() {
		using namespace SlidingTilesData;
		//The last move of the sliding tiles game is always making the empty tile go to the bottom right corner
		if (board.access(boardSize - 1, boardSize - 1) != boardSize * boardSize) return true;
		//Then check if the board is ordered to trigger a win
		else if (SlidingTilesFunctions::isBoardOrdered()) {
			return false;
		}
		else return true;
	}
}
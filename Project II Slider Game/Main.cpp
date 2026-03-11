#include "UserFunctions.hpp"
#include "SlidingTilesFunctions.hpp"

int main() {
	bool playing = true;
	while (playing) {
		SlidingTilesFunctions::startGame(UserFunctions::selectDifficulty());
		playing = UserFunctions::getPlayAgain();
	}

	return 0;
}
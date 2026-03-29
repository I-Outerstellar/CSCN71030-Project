#include "UserFunctions.hpp"

int main() {
	while (UserFunctions::selectDifficulty()) {
		while (UserFunctions::performSlide());
	}

	return 0;
}
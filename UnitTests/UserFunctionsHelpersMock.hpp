#pragma once
#include "../Project II Slider Game/SlidingTilesEnums.hpp"
#include <string>

namespace UserFunctionsHelpersMock {
	void trySlide(SlidingTilesEnums::Direction direction);

	bool continueGame(std::string fileName);
}
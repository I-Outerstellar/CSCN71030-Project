#pragma once
#include <string>
#include <vector>

namespace SlidingTilesFunctionsMock {
	void writeScore(std::string filename);

	std::vector<unsigned int> loadScores(std::string filename);
}


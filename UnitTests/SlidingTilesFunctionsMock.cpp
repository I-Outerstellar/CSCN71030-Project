#include "SlidingTilesFunctionsMock.hpp"
#include "../Project II Slider Game/SlidingTilesFunctionsHelpers.hpp"
#include "../Project II Slider Game/SlidingTilesData.hpp"
#include <fstream>
#include <algorithm>

namespace SlidingTilesFunctionsMock {
	void writeScore(std::string filename) {

		// Open file to append score
		std::ofstream outFile(filename, std::ios::app);
		if (outFile.is_open()) {
			outFile << SlidingTilesData::slides << std::endl;
			outFile.close();
		}
	}

	std::vector<unsigned int> loadScores(std::string filename) {
		std::vector<unsigned int> scores;

		// Read all scores from file
		std::ifstream inFile(filename);
		if (inFile.is_open()) {
			unsigned int score;
			while (inFile >> score) {
				scores.push_back(score);
			}
			inFile.close();
		}

		// Sort scores (lowest is best)
		std::sort(scores.begin(), scores.end());

		// Keep only top 10
		if (scores.size() > SlidingTilesFunctionsHelpers::LEADERBOARD_SIZE) {
			scores.resize(SlidingTilesFunctionsHelpers::LEADERBOARD_SIZE);
		}

		return scores;
	}
}
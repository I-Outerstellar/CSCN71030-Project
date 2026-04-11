#pragma once
#include "include/GameObjects.hpp"
#include "../Project II Slider Game/SlidingTilesEnums.hpp"

namespace SlidingTilesScenes {
    namespace LeaderboardScene {
        // Creates and returns the leaderboard scene
        GameObjects::GameScene* createLeaderboardScene();

        // Switches to a different difficulty leaderboard
        void switchDifficulty(SlidingTilesEnums::Difficulty difficulty);
    }
}

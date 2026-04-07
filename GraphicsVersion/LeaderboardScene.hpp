#pragma once
#include "include/GameObjects.hpp"
#include "include/GameControllers.hpp"
#include "../Project II Slider Game/SlidingTilesFunctions.hpp"
#include "../Project II Slider Game/SlidingTilesData.hpp"

namespace SlidingTilesScenes {
    namespace LeaderboardScene {
        // Creates and returns the leaderboard scene
        GameObjects::GameScene& create();


        // Set callback for back button
        void setBackButtonCallback(std::function<void()> callback);

        // Updates the displayed scores for current difficulty
        void updateScores();

        // Switches to a different difficulty leaderboard
        void switchDifficulty(SlidingTilesEnums::Difficulty difficulty);
    }
}

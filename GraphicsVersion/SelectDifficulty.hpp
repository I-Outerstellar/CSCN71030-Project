#pragma once
#include "include/GameObjects.hpp"
#include "include/GameControllers.hpp"
#include "../Project II Slider Game/SlidingTilesEnums.hpp"

namespace SlidingTilesScenes {

    namespace SelectDifficulty {
        extern GameObjects::GameScene scene;

        // Store selected difficulty so other scenes (gameplay/leaderboard) can use it
        extern SlidingTilesEnums::Difficulty selectedDifficulty;

        void setup();
    };

}

#pragma once
#include "include/GameObjects.hpp"
#include "include/GameControllers.hpp"
#include "../Project II Slider Game/SlidingTilesFunctions.hpp"

namespace GameScenes {

    class SelectDifficulty {
    public:
        static GameObjects::GameScene scene;

        // Store selected difficulty so other scenes (gameplay/leaderboard) can use it
        static SlidingTilesEnums::Difficulty selectedDifficulty;

        static void setup();
    };

}

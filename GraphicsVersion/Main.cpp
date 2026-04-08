#include <SFML/Graphics.hpp>
#include "include/GameControllers.hpp"
#include "include/GameObjects.hpp"
#include "GameplayScene.hpp"
#include "LeaderboardScene.hpp"
#include "SelectDifficulty.hpp"
#include <iostream>

int main()
{
    // Create all scenes
    static GameObjects::GameScene selectDiff = SlidingTilesScenes::SelectDifficulty::setup();
    static GameObjects::GameScene& gameplay = SlidingTilesScenes::GameplayScene::createGameplayScene(); // & and lowercase p
    static GameObjects::GameScene& leaderboard = SlidingTilesScenes::LeaderboardScene::create();

    SlidingTilesScenes::LeaderboardScene::setBackButtonCallback([] {
        std::cout << "Back button pressed - switching to gameplay!" << std::endl;
        SceneControl::switchScene(gameplay);
        });

    SceneControl::switchScene(leaderboard);
    WindowControl::beginWindowLoop("Sliding Puzzle", sf::State::Fullscreen, 30);
}

#include <SFML/Graphics.hpp>
#include "include/GameControllers.hpp"
#include "include/GameObjects.hpp"
#include "ScenesContainer.hpp"
#include "GameplayScene.hpp"
#include "SelectDifficulty.hpp"
#include "LeaderboardScene.hpp"
#include <iostream>

GameObjects::GameScene* ScenesContainer::selectDiffScene = nullptr;
GameObjects::GameScene* ScenesContainer::gameplayScene = nullptr;
GameObjects::GameScene* ScenesContainer::leaderboardScene = nullptr;

int main()
{
    ScenesContainer::selectDiffScene = SlidingTilesScenes::SelectDifficulty::setup();
    ScenesContainer::gameplayScene = SlidingTilesScenes::GameplayScene::createGameplayScene();
    ScenesContainer::leaderboardScene = SlidingTilesScenes::LeaderboardScene::create();

    SlidingTilesScenes::LeaderboardScene::setBackButtonCallback([] {
        std::cout << "Back button pressed - switching to gameplay!" << std::endl;
        SceneControl::switchScene(*ScenesContainer::selectDiffScene);
    });

    SceneControl::switchScene(*ScenesContainer::selectDiffScene);
    WindowControl::beginWindowLoop("Sliding Puzzle", sf::State::Fullscreen, 30);
}

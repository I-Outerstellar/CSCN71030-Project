#include <SFML/Graphics.hpp>
#include "include/GameControllers.hpp"
#include "include/GameObjects.hpp"
#include "GameplayScene.hpp"
#include "LeaderboardScene.hpp"
#include <iostream>

int main()
{
    // Create both scenes
    static GameObjects::GameScene& gameplay = createGameplayScene(); // & and lowercase p
    static GameObjects::GameScene& leaderboard = SlidingTilesScenes::LeaderboardScene::create();

    SlidingTilesScenes::LeaderboardScene::setBackButtonCallback([] {
        std::cout << "Back button pressed - switching to gameplay!" << std::endl;
        SceneControl::switchScene(gameplay);
        });

    SceneControl::switchScene(leaderboard);
    WindowControl::beginWindowLoop("Sliding Puzzle", sf::State::Windowed, 30);
    return 0;
}          
#include <SFML/Graphics.hpp>
#include "include/GameControllers.hpp"
#include "include/GameObjects.hpp"
#include "GameplayScene.hpp"
#include "SelectDifficulty.hpp"
#include <iostream>

int main()
{
    static GameObjects::GameScene selectDiff = SlidingTilesScenes::SelectDifficulty::scene;
    SlidingTilesScenes::SelectDifficulty::setup();
    static GameObjects::GameScene gameplay = createGameplayScene();
    static GameObjects::GameScene leaderboard; // = function();

    SceneControl::switchScene(selectDiff);
    WindowControl::beginWindowLoop("Demo", sf::State::Fullscreen, 30);
}
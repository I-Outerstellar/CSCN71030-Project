#include <SFML/Graphics.hpp>
#include "include/GameControllers.hpp"
#include "include/GameObjects.hpp"
#include "GameplayScene.hpp"
#include <iostream>

int main()
{
    GameObjects::GameScene selectDiff; // = function();
    GameObjects::GameScene gameplay = createGameplayScene();
    GameObjects::GameScene leaderboard; // = function();

    SceneControl::switchScene(gameplay);
    WindowControl::beginWindowLoop("Demo", sf::State::Fullscreen, 30);
}
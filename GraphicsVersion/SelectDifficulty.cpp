#include "SelectDifficulty.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Project II Slider Game/SlidingTilesFunctions.hpp"
#include "../Project II Slider Game/SlidingTilesData.hpp"
#include "ScenesContainer.hpp"
#include "GameplayScene.hpp"

using namespace GameObjects;
using namespace SlidingTilesScenes;

namespace {
    GameObjects::GameScene scene;
    bool created = false;

    sf::Font font("C:\\Windows\\Fonts\\BKANT.TTF");
    std::shared_ptr<TextButton> easy, medium, hard, insane, leaderboard;
}

namespace {
    std::shared_ptr<TextButton> createButton(std::string text, sf::Vector2f pos, SlidingTilesEnums::Difficulty diff) {

        auto button = GameButton::create<TextButton>(sf::Text(font), 1);

        button->changeText(text);
        button->setPosition(pos);
        button->setSize({ 300, 80 });
        button->setFillColor(sf::Color::Yellow);
        button->text.setFillColor(sf::Color::Black);

        // Hover effect
        button->onMouseMovement = [button](sf::Vector2f, sf::Vector2i) {
            if (button->isMouseHovering())
                button->setFillColor(sf::Color::Green);
            else
                button->setFillColor(sf::Color::Yellow);
            };

        // Click behavior
        button->onClick = [diff](sf::Mouse::Button mouseButton) {
            if (mouseButton != sf::Mouse::Button::Left) return;

            SlidingTilesData::currentDifficulty = diff;

            //Switch scene
            ScenesContainer::gameplayScene = SlidingTilesScenes::GameplayScene::createGameplayScene();
            SceneControl::switchScene(*ScenesContainer::gameplayScene);

            };

        return button;
    }
}

GameScene* SelectDifficulty::setup() {
    if (created) return &scene;

    easy = createButton("Easy", { 250, 100 }, SlidingTilesEnums::Difficulty::EASY); //Access violation occurred here, somehow
    medium = createButton("Medium", { 250, 200 }, SlidingTilesEnums::Difficulty::MEDIUM);
    hard = createButton("Hard", { 250, 300 }, SlidingTilesEnums::Difficulty::HARD);
    insane = createButton("Insane", { 250, 400 }, SlidingTilesEnums::Difficulty::INSANE);

    leaderboard = GameButton::create<TextButton>(sf::Text(font, "Leaderboard"));
    leaderboard->setPosition({ 250, 500 });
    leaderboard->setSize({ 300, 80 });
    leaderboard->setFillColor(sf::Color::Yellow);
    leaderboard->text.setFillColor(sf::Color::Black);

    // Hover effect
    leaderboard->onMouseMovement = [](sf::Vector2f, sf::Vector2i) {
        if (leaderboard->isMouseHovering())
            leaderboard->setFillColor(sf::Color::Green);
        else
            leaderboard->setFillColor(sf::Color::Yellow);
        };

    // Click behavior
    leaderboard->onClick = [](sf::Mouse::Button mouseButton) {
        if (mouseButton != sf::Mouse::Button::Left) return;
        SceneControl::switchScene(*ScenesContainer::leaderboardScene);
        };

    scene.add(easy).add(medium).add(hard).add(insane).add(leaderboard);

    created = true;
    return &scene;
}

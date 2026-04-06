#include "SelectDifficulty.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace GameObjects;
using namespace GameScenes;

GameScene SelectDifficulty::scene;
SlidingTilesEnums::Difficulty SelectDifficulty::selectedDifficulty = SlidingTilesEnums::Difficulty::EASY;

void SelectDifficulty::setup() {

    static sf::Font font("C:\\Windows\\Fonts\\BKANT.TTF");

    auto createButton = [&](std::string text, sf::Vector2f pos, SlidingTilesEnums::Difficulty diff) {

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

            // Save selected difficulty (IMPORTANT for leaderboard + gameplay)
            SelectDifficulty::selectedDifficulty = diff;

            std::cout << "Selected difficulty: " << static_cast<int>(diff) << "\n";

            // Start game logic
            SlidingTilesFunctions::startGame(diff);

           
            };

        return button;
        };

    auto easy = createButton("Easy", { 250, 100 }, SlidingTilesEnums::Difficulty::EASY);
    auto medium = createButton("Medium", { 250, 200 }, SlidingTilesEnums::Difficulty::MEDIUM);
    auto hard = createButton("Hard", { 250, 300 }, SlidingTilesEnums::Difficulty::HARD);
    auto insane = createButton("Insane", { 250, 400 }, SlidingTilesEnums::Difficulty::INSANE);

    scene.add(easy).add(medium).add(hard).add(insane);
}

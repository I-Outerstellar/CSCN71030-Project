#include "LeaderboardScene.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace GameObjects;
using namespace SlidingTilesScenes;

namespace {
    // The main scene object
    GameScene scene;
    bool created = false;

    // Font for text
    sf::Font font("C:\\Windows\\Fonts\\BKANT.TTF");

    // Current difficulty being displayed
    SlidingTilesEnums::Difficulty currentDifficulty = SlidingTilesEnums::Difficulty::EASY;

    // UI Elements
    std::shared_ptr<TextBox> titleText;
    std::shared_ptr<TextBox> scoreList[10];  // 10 score entries
    std::shared_ptr<TextButton> backButton;
    std::shared_ptr<TextButton> easyButton;
    std::shared_ptr<TextButton> mediumButton;
    std::shared_ptr<TextButton> hardButton;
    std::shared_ptr<TextButton> insaneButton;

    // Callback for back button
    std::function<void()> backButtonCallback = nullptr;

    // Helper to get difficulty name as string
    std::string getDifficultyName(SlidingTilesEnums::Difficulty diff) {
        switch (diff) {
        case SlidingTilesEnums::Difficulty::EASY:   return "EASY";
        case SlidingTilesEnums::Difficulty::MEDIUM: return "MEDIUM";
        case SlidingTilesEnums::Difficulty::HARD:   return "HARD";
        case SlidingTilesEnums::Difficulty::INSANE: return "INSANE";
        }
        return "UNKNOWN";
    }

    // Helper to create a button with hover effect
    std::shared_ptr<TextButton> createButton(std::string text, sf::Vector2f pos, sf::Color color) {
        auto button = GameButton::create<TextButton>(sf::Text(font), 1);
        button->changeText(text);
        button->setPosition(pos);
        button->setSize({ 120, 50 });
        button->setFillColor(color);
        button->text.setFillColor(sf::Color::Black);
        button->text.setCharacterSize(20);

        button->onMouseMovement = [button](sf::Vector2f, sf::Vector2i) {
            if (button->isMouseHovering())
                button->setFillColor(sf::Color::Green);
            else
                button->setFillColor(sf::Color::Yellow);
            };

        return button;
    }
}

namespace SlidingTilesScenes {
    namespace LeaderboardScene {

        void updateScores() {
            // Load scores for current difficulty
            std::vector<unsigned int> scores = SlidingTilesFunctions::loadScores(currentDifficulty);

            // Update title to show current difficulty
            titleText->changeText("LEADERBOARD - " + getDifficultyName(currentDifficulty));

            // Clear previous score displays
            for (int i = 0; i < 10; i++) {
                if (scoreList[i]) {
                    scoreList[i]->changeText("");
                }
            }

            // Display top 10 scores
            for (int i = 0; i < scores.size() && i < 10; i++) {
                std::string entry = std::to_string(i + 1) + ". " + std::to_string(scores[i]) + " moves";
                scoreList[i]->changeText(entry);
            }

            // If no scores, show message
            if (scores.empty()) {
                scoreList[0]->changeText("No scores yet! Play a game first.");
            }
        }

        void switchDifficulty(SlidingTilesEnums::Difficulty difficulty) {
            currentDifficulty = difficulty;
            updateScores();
        }

        void setBackButtonCallback(std::function<void()> callback) {
            backButtonCallback = callback;
        }

        GameScene& create() {
            if (created) return scene;

            // Get screen size
            float screenWidth = static_cast<float>(sf::VideoMode::getDesktopMode().size.x);
            float screenHeight = static_cast<float>(sf::VideoMode::getDesktopMode().size.y);

            // Set background color
            scene.backgroundColour = sf::Color(30, 45, 75);

            //TITLE
            titleText = GameShape::create<TextBox>(sf::Text(font), 40, 2);
            titleText->setSize({ 600, 60 });
            titleText->setPosition({ screenWidth / 2 - 300, 50 });
            titleText->setFillColor(sf::Color::Transparent);
            titleText->text.setFillColor(sf::Color::White);
            titleText->text.setCharacterSize(40);
            scene.add(titleText);

            //DIFFICULTY BUTTONS 
            float buttonY = 130;
            float buttonStartX = screenWidth / 2 - 260;

            easyButton = createButton("EASY", { buttonStartX, buttonY }, sf::Color::Yellow);
            mediumButton = createButton("MEDIUM", { buttonStartX + 130, buttonY }, sf::Color::Yellow);
            hardButton = createButton("HARD", { buttonStartX + 260, buttonY }, sf::Color::Yellow);
            insaneButton = createButton("INSANE", { buttonStartX + 390, buttonY }, sf::Color::Yellow);

            // Button click handlers
            easyButton->onClick = [](sf::Mouse::Button btn) {
                if (btn == sf::Mouse::Button::Left)
                    switchDifficulty(SlidingTilesEnums::Difficulty::EASY);
                };
            mediumButton->onClick = [](sf::Mouse::Button btn) {
                if (btn == sf::Mouse::Button::Left)
                    switchDifficulty(SlidingTilesEnums::Difficulty::MEDIUM);
                };
            hardButton->onClick = [](sf::Mouse::Button btn) {
                if (btn == sf::Mouse::Button::Left)
                    switchDifficulty(SlidingTilesEnums::Difficulty::HARD);
                };
            insaneButton->onClick = [](sf::Mouse::Button btn) {
                if (btn == sf::Mouse::Button::Left)
                    switchDifficulty(SlidingTilesEnums::Difficulty::INSANE);
                };

            scene.add(easyButton).add(mediumButton).add(hardButton).add(insaneButton);

            // ========== SCORE LIST ==========
            float scoreStartY = 220;
            float scoreSpacing = 50;

            for (int i = 0; i < 10; i++) {
                scoreList[i] = GameShape::create<TextBox>(sf::Text(font), 30, 1);
                scoreList[i]->setSize({ 400, 45 });
                scoreList[i]->setPosition({ screenWidth / 2 - 200, scoreStartY + i * scoreSpacing });
                scoreList[i]->setFillColor(sf::Color::Transparent);
                scoreList[i]->text.setFillColor(sf::Color::White);
                scoreList[i]->text.setCharacterSize(30);
                scene.add(scoreList[i]);
            }

            // ========== BACK BUTTON ==========
            backButton = createButton("BACK TO MENU", { screenWidth / 2 - 100, screenHeight - 100 }, sf::Color::Yellow);
            backButton->setSize({ 200, 50 });
            backButton->onClick = [](sf::Mouse::Button btn) {
                if (btn == sf::Mouse::Button::Left) {
                    if (backButtonCallback) {
                        backButtonCallback();
                    }
                    std::cout << "Returning to menu..." << std::endl;
                }
                };
            scene.add(backButton);

            // Load initial scores
            updateScores();

            created = true;
            return scene;
        }
    }
}
#include "GameplayScene.hpp"
#include "include/GameObjects.hpp"
#include "include/GameControllers.hpp"
#include "../Project II Slider Game/SlidingTilesData.hpp"
#include "../Project II Slider Game/SlidingTilesFunctions.hpp"
#include <unordered_map>
#include <iostream>

namespace {
	static GameObjects::GameScene scene;
	sf::Font font("C:\\Windows\\Fonts\\BKANT.TTF");
	unsigned int screenSize = 1000;//WindowControl::gameWindow().getSize().y;
	std::unordered_map<size_t, std::shared_ptr<GameObjects::TextBox>> boardTiles;
	unsigned int divisor;
	unsigned int buttonSize;

	std::shared_ptr<GameObjects::RectangleButton> upButton;
	std::shared_ptr<GameObjects::RectangleButton> downButton;
	std::shared_ptr<GameObjects::RectangleButton> leftButton;
	std::shared_ptr<GameObjects::RectangleButton> rightButton;
}

namespace {
	sf::Vector2f getPosition(size_t row, size_t column) {
		return sf::Vector2f(
			static_cast<float>(buttonSize / 2 + buttonSize * static_cast<unsigned int>(row)), 
			static_cast<float>(buttonSize / 2 + buttonSize * static_cast<unsigned int>(column))
		);
	}

	std::shared_ptr<GameObjects::RectangleButton>
	createDirectionButton(SlidingTilesEnums::Direction direction) {
		auto button = GameObjects::GameButton::create<GameObjects::RectangleButton>(0);
		button->setFillColor(sf::Color(255, 255, 255, 51));
		button->onClickRelease = [direction](sf::Mouse::Button button) {
			if (button != sf::Mouse::Button::Left) return;
			std::cout << static_cast<int>(direction) << '\n';
			//std::cout << "Current Row: " << SlidingTilesData::currentRow << " | Current Column: " << SlidingTilesData::currentColumn << '\n';
			size_t oldRow = SlidingTilesData::currentRow, oldColumn = SlidingTilesData::currentColumn;
			bool success = SlidingTilesFunctions::slide(direction);
			if (!success) return;
			std::cout << "Current Row: " << SlidingTilesData::currentRow << " | Current Column: " << SlidingTilesData::currentColumn << '\n';
			size_t newRow = SlidingTilesData::currentRow, newColumn = SlidingTilesData::currentColumn;
			auto tile1 = boardTiles.at(SlidingTilesData::board.access(oldRow, oldColumn));
			auto tile2 = boardTiles.at(SlidingTilesData::board.access(newRow, newColumn));
			if (tile1 == nullptr || tile2 == nullptr) return;
			std::cout << "Swapped " << SlidingTilesData::board.access(oldRow, oldColumn)
				<< " and " << SlidingTilesData::board.access(newRow, newColumn) << '\n';
			tile2->setPosition(getPosition(newColumn, newRow));
			tile1->setPosition(getPosition(oldColumn, oldRow));
			};

		button->setSize(sf::Vector2f(static_cast<float>(buttonSize), static_cast<float>(buttonSize)));
		return button;
	}
}

GameObjects::GameScene&
createGameplayScene() {
	SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::EASY);
	divisor = static_cast<unsigned int>(SlidingTilesData::currentDifficulty) + 1;
	buttonSize = screenSize / divisor;

	upButton = createDirectionButton(SlidingTilesEnums::Direction::UP);
	//upButton->setFillColor(sf::Color::Red);
	downButton = createDirectionButton(SlidingTilesEnums::Direction::DOWN);
	//downButton->setFillColor(sf::Color::Magenta);
	leftButton = createDirectionButton(SlidingTilesEnums::Direction::LEFT);
	//leftButton->setFillColor(sf::Color::Green);
	rightButton = createDirectionButton(SlidingTilesEnums::Direction::RIGHT);
	//rightButton->setFillColor(sf::Color::Yellow);

	sf::Vector2f position = sf::Vector2f(static_cast<float>(buttonSize / 2), static_cast<float>(buttonSize / 2));
	for (unsigned int i = 0; i < divisor - 1; i++) {
		for (unsigned int j = 0; j < divisor - 1; j++) {
			auto numberBox = GameObjects::GameShape::create<GameObjects::TextBox>(font, 30, 2);
			int val = i * (divisor - 1) + j + 1;
			if ((i+1) * (j+1) == (divisor - 1) * (divisor - 1)) {
				numberBox->text.setString("Empty");
				numberBox->setSize(sf::Vector2f(static_cast<float>(buttonSize), static_cast<float>(buttonSize)));
				numberBox->setPosition({ position.x + buttonSize * j, position.y + buttonSize * i });
				numberBox->setFillColor(sf::Color(0, 0, 0, 51));
			}
			else {
				numberBox->text.setString(std::to_string(val));
				numberBox->setSize(sf::Vector2f(static_cast<float>(buttonSize), static_cast<float>(buttonSize)));
				numberBox->setPosition({ position.x + buttonSize * j, position.y + buttonSize * i });
				numberBox->setFillColor(sf::Color::Black);
			}
			boardTiles.try_emplace(val, numberBox);
			scene.add(boardTiles.at(val));
		}
	}
	
	static std::function<void()> updateButtonPos = []() {
		upButton->setPosition(getPosition(SlidingTilesData::currentColumn, SlidingTilesData::currentRow - 1));
		downButton->setPosition(getPosition(SlidingTilesData::currentColumn, SlidingTilesData::currentRow + 1));
		leftButton->setPosition(getPosition(SlidingTilesData::currentColumn - 1, SlidingTilesData::currentRow));
		rightButton->setPosition(getPosition(SlidingTilesData::currentColumn + 1, SlidingTilesData::currentRow));
		};
	scene.addBeforeDrawFunction(updateButtonPos);
	
	scene.switchedFrom = [](GameObjects::GameScene& sceneAfter) {
		for (unsigned int i = 0; i < (divisor - 1) * (divisor - 1); i++) scene.remove(boardTiles.at(i));
		boardTiles.clear();
		return true;
	};

	scene.add(upButton).add(downButton).add(leftButton).add(rightButton);

	return scene;
}
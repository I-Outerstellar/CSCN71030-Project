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
	unsigned int screenSize = sf::VideoMode::getDesktopMode().size.y;
	std::unordered_map<size_t, std::shared_ptr<GameObjects::TextBox>> boardTiles;
	unsigned int divisor;
	unsigned int buttonSize;
	constexpr float OUTLINE_THICKNESS = 3;

	std::shared_ptr<GameObjects::RectangleButton> upButton;
	std::shared_ptr<GameObjects::RectangleButton> downButton;
	std::shared_ptr<GameObjects::RectangleButton> leftButton;
	std::shared_ptr<GameObjects::RectangleButton> rightButton;
	std::shared_ptr<GameObjects::TextBox> slideCounter
		= GameObjects::GameShape::create<GameObjects::TextBox>(font, 30, 0);
}

namespace {
	sf::Vector2f getBoardPosition(size_t row, size_t column) {
		/*Perform a calculation to get button's position*/
		return sf::Vector2f(
			static_cast<float>(buttonSize / 2 + buttonSize * static_cast<unsigned int>(row)),
			static_cast<float>(buttonSize / 2 + buttonSize * static_cast<unsigned int>(column))
		);
	}

	void checkWinCondition() {
		if (SlidingTilesData::board.access(divisor - 2, divisor - 2) != (divisor - 1) * (divisor - 1))
			return;
		else if (!SlidingTilesFunctions::isBoardOrdered())
			return;
		else {
			slideCounter->text.setFillColor(sf::Color(225, 225, 0));
			slideCounter->changeText("You win!");
			StateControl::Modifiers::disableInputAccepting(5000);
			static std::function<void()> waitOnTimer = []() {
				if (StateControl::Accessors::canAcceptInput()) {
					scene.removeAfterDrawFunction(waitOnTimer);
					//SceneControl::switchScene(to whatever screen)
				}
			};
			scene.addAfterDrawFunction(waitOnTimer);
		}
	}

	std::function<void()> updateButtonPos = []() {
		/*Set button positions relative to the current tile*/
		upButton->setPosition(getBoardPosition(SlidingTilesData::currentColumn, SlidingTilesData::currentRow - 1)
			+ sf::Vector2f(OUTLINE_THICKNESS, OUTLINE_THICKNESS));
		downButton->setPosition(getBoardPosition(SlidingTilesData::currentColumn, SlidingTilesData::currentRow + 1)
			+ sf::Vector2f(OUTLINE_THICKNESS, OUTLINE_THICKNESS));
		leftButton->setPosition(getBoardPosition(SlidingTilesData::currentColumn - 1, SlidingTilesData::currentRow)
			+ sf::Vector2f(OUTLINE_THICKNESS, OUTLINE_THICKNESS));
		rightButton->setPosition(getBoardPosition(SlidingTilesData::currentColumn + 1, SlidingTilesData::currentRow)
			+ sf::Vector2f(OUTLINE_THICKNESS, OUTLINE_THICKNESS));

		/*Set the button visibility based on if they are on the border or not*/
		upButton->visible = SlidingTilesData::board.canAccess(SlidingTilesData::currentColumn, SlidingTilesData::currentRow - 1);
		downButton->visible = SlidingTilesData::board.canAccess(SlidingTilesData::currentColumn, SlidingTilesData::currentRow + 1);
		leftButton->visible = SlidingTilesData::board.canAccess(SlidingTilesData::currentColumn - 1, SlidingTilesData::currentRow);
		rightButton->visible = SlidingTilesData::board.canAccess(SlidingTilesData::currentColumn + 1, SlidingTilesData::currentRow);
	};

	auto createDirectionButtonHandler(SlidingTilesEnums::Direction direction) {
		return [direction](sf::Mouse::Button button) {
			/*Must be left click*/
			if (button != sf::Mouse::Button::Left) return;

			/*Get the two tiles which the slide occurs, or not if the slide fails*/
			size_t oldRow = SlidingTilesData::currentRow, oldColumn = SlidingTilesData::currentColumn;
			bool success = SlidingTilesFunctions::slide(direction);
			if (!success) return;
			size_t newRow = SlidingTilesData::currentRow, newColumn = SlidingTilesData::currentColumn;
			auto tile1 = boardTiles.at(SlidingTilesData::board.access(oldRow, oldColumn));
			auto tile2 = boardTiles.at(SlidingTilesData::board.access(newRow, newColumn));
			if (tile1 == nullptr || tile2 == nullptr) return; //Error handling case

			/*Change the graphical position of the tiles*/
			tile2->setPosition(getBoardPosition(newColumn, newRow));
			tile1->setPosition(getBoardPosition(oldColumn, oldRow));
			SlidingTilesData::slides++;
			slideCounter->changeText("Slides: " + std::to_string(SlidingTilesData::slides));
			checkWinCondition();
		};
	}

	std::shared_ptr<GameObjects::RectangleButton> createDirectionButton(SlidingTilesEnums::Direction direction) {
		/*Create the button*/
		auto button = GameObjects::GameButton::create<GameObjects::RectangleButton>(0);

		/*Stylize the button*/
		button->setFillColor(sf::Color::Transparent);
		button->setOutlineColor(sf::Color(255, 255, 255, 51));
		button->setOutlineThickness(OUTLINE_THICKNESS);

		/*Code button behaviour*/
		button->onClickRelease = createDirectionButtonHandler(direction);

		/*Set the button's size, affected by difficulty*/
		button->setSize(
			sf::Vector2f(
				static_cast<float>(buttonSize) - OUTLINE_THICKNESS * 2,
				static_cast<float>(buttonSize) - OUTLINE_THICKNESS * 2
			)
		);
		return button;
	}
}

void startGame(SlidingTilesEnums::Difficulty difficulty) {
	SlidingTilesData::currentDifficulty = difficulty;
	SlidingTilesFunctions::startGame(difficulty);
	SlidingTilesFunctions::shuffle();
}

GameObjects::GameScene& createGameplayScene() {
	startGame(SlidingTilesEnums::Difficulty::HARD);
	divisor = static_cast<unsigned int>(SlidingTilesData::currentDifficulty) + 1;
	buttonSize = screenSize / divisor;

	/*Set score text attributes*/
	slideCounter->setSize({ static_cast<float>(buttonSize * divisor), static_cast<float>(buttonSize / 2) });
	slideCounter->changeText("Slides: 0");
	slideCounter->setFillColor(sf::Color::Transparent);

	/*Create buttons*/
	upButton = createDirectionButton(SlidingTilesEnums::Direction::UP);
	downButton = createDirectionButton(SlidingTilesEnums::Direction::DOWN);
	leftButton = createDirectionButton(SlidingTilesEnums::Direction::LEFT);
	rightButton = createDirectionButton(SlidingTilesEnums::Direction::RIGHT);

	/*Set the position of the top left tile*/
	sf::Vector2f position = sf::Vector2f(static_cast<float>(buttonSize / 2), static_cast<float>(buttonSize / 2));
	/*Then place all numbered tiles in the position they should be in*/
	for (unsigned int i = 0; i < divisor - 1; i++) {
		for (unsigned int j = 0; j < divisor - 1; j++) {
			/*Create the numbered tile and assign the proper value*/
			auto numberBox = GameObjects::GameShape::create<GameObjects::TextBox>(font, buttonSize / 10, 2);
			size_t val = SlidingTilesData::board.access(i, j);
			if ((i+1) * (j+1) == (divisor - 1) * (divisor - 1)) { //If it's the bottom right tile
				numberBox->changeText("Empty");
				numberBox->setSize(sf::Vector2f(static_cast<float>(buttonSize), static_cast<float>(buttonSize)));
				numberBox->setPosition(getBoardPosition(j, i));
				numberBox->setFillColor(sf::Color(0, 0, 0, 51));
			}
			else { //Else, it is a numbered tile
				numberBox->changeText(std::to_string(val));
				numberBox->setSize(sf::Vector2f(static_cast<float>(buttonSize), static_cast<float>(buttonSize)));
				numberBox->setPosition(getBoardPosition(j, i));
				numberBox->setFillColor(sf::Color::Black);
			}
			boardTiles.try_emplace(val, numberBox);
			scene.add(boardTiles.at(val));
		}
	}
	
	scene.addBeforeDrawFunction(updateButtonPos);
	
	scene.switchedFrom = [](GameObjects::GameScene& sceneAfter) {
		/*Clear all tiles and functions*/
		for (unsigned int i = 1; i < (divisor - 1) * (divisor - 1) + 1; i++) scene.remove(boardTiles.at(i));
		scene.removeBeforeDrawFunction(updateButtonPos);
		scene.remove(upButton).remove(downButton).remove(leftButton).remove(rightButton).remove(slideCounter);
		boardTiles.clear();
		return true;
	};

	/*Add all buttons*/
	scene.add(upButton).add(downButton).add(leftButton).add(rightButton).add(slideCounter);

	return scene;
}
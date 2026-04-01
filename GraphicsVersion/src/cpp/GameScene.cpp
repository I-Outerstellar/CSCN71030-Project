#include "../headers/GameScene.hpp"
#include "../headers/GameButton.hpp"
#include "../headers/GameShape.hpp"
#include "../headers/SceneData.hpp"
#include "../headers/GameWindow.hpp"
#include "../headers/StateControl.hpp"
#include <algorithm>

using namespace GameObjects;

GameScene::GameScene() {
	this->keyPressFunctions[StateControl::scancodeToInt(sf::Keyboard::Scancode::Escape)] = []() {
		window.close();
	};
}

void GameScene::sortButtons() {
	std::stable_sort(this->sceneButtons.begin(), this->sceneButtons.end(),
		[](const std::shared_ptr<GameButton>& element1, const std::shared_ptr<GameButton>& element2) {
			return element1->getZIndex() > element2->getZIndex();
		});
}

void GameScene::sortShapes() {
	std::stable_sort(this->sceneShapes.begin(), this->sceneShapes.end(),
		[](const std::shared_ptr<GameShape>& element1, const std::shared_ptr<GameShape>& element2) {
			return element1->getZIndex() > element2->getZIndex();
		});
}

std::vector<std::shared_ptr<GameButton>> GameScene::getSceneButtons() {
	return this->sceneButtons;
}

std::vector<std::shared_ptr<GameShape>> GameScene::getSceneShapes() {
	return this->sceneShapes;
}

bool GameScene::contains(const std::shared_ptr<GameButton>& button) {
	return std::find(this->sceneButtons.begin(), this->sceneButtons.end(), button) != this->sceneButtons.end();
}

bool GameScene::contains(const std::shared_ptr<GameShape>& shape) {
	return std::find(this->sceneShapes.begin(), this->sceneShapes.end(), shape) != this->sceneShapes.end();
}

GameScene& GameScene::add(const std::shared_ptr<GameButton>& button) {
	if (this->contains(button)) return *this;
	this->sceneButtons.push_back(button);

	this->sortButtons();
	return *this;
}

GameScene& GameScene::add(const std::shared_ptr<GameShape>& shape) {
	if (this->contains(shape)) return *this;
	this->sceneShapes.push_back(shape);

	this->sortShapes();
	return *this;
}

GameScene& GameScene::remove(const std::shared_ptr<GameButton>& button) {
	auto iter = std::find(this->sceneButtons.begin(), this->sceneButtons.end(), button);
	if (iter != this->sceneButtons.end())
		this->sceneButtons.erase(iter);
	return *this;
}

GameScene& GameScene::remove(const std::shared_ptr<GameShape>& shape) {
	auto iter = std::find(this->sceneShapes.begin(), this->sceneShapes.end(), shape);
	if (iter != this->sceneShapes.end())
		this->sceneShapes.erase(iter);
	return *this;
}

bool GameScene::hasProperty(const std::string propertyName) {
	return this->properties.find(propertyName) != this->properties.end();
}

GameScene& GameScene::deleteProperty(const std::string propertyName) {
	this->properties.erase(propertyName);
	return *this;
}

std::vector<std::function<void()>*> GameScene::getBeforeDrawFunctions() {
	return this->beforeDraw;
}

std::vector<std::function<void()>*> GameScene::getAfterDrawFunctions() {
	return this->afterDraw;
}

bool GameScene::containsBeforeDrawFunction(std::function<void()>& func) {
	return std::find(beforeDraw.begin(), beforeDraw.end(), &func) != beforeDraw.end();
}

bool GameScene::containsAfterDrawFunction(std::function<void()>& func) {
	return std::find(afterDraw.begin(), afterDraw.end(), &func) != afterDraw.end();
}

GameScene& GameScene::addBeforeDrawFunction(std::function<void()>& func) {
	if (GameScene::containsBeforeDrawFunction(func)) return *this;
	beforeDraw.push_back(&func);
	return *this;
}

GameScene& GameScene::addAfterDrawFunction(std::function<void()>& func) {
	if (GameScene::containsAfterDrawFunction(func)) return *this;
	afterDraw.push_back(&func);
	return *this;
}

GameScene& GameScene::removeBeforeDrawFunction(std::function<void()>& func) {
	auto iter = std::find(beforeDraw.begin(), beforeDraw.end(), &func);
	if (iter != beforeDraw.end())
		beforeDraw.erase(iter);
	return *this;
}

GameScene& GameScene::removeAfterDrawFunction(std::function<void()>& func) {
	auto iter = std::find(afterDraw.begin(), afterDraw.end(), &func);
	if (iter != afterDraw.end())
		afterDraw.erase(iter);
	return *this;
}
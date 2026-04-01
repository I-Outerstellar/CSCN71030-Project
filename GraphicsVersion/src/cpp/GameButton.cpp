#include "../headers/GameButton.hpp"
#include "../headers/GameScene.hpp"
#include "../headers/SceneControl.hpp"

GameObjects::GameButton& GameObjects::GameButton::setZIndex(unsigned int zIndex) {
	this->zIndex = zIndex;
	SceneControl::currentScene().setProperty<void*>("ResortElements", nullptr);
	return *this;
}
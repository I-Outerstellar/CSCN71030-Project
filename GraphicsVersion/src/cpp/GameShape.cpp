#include "../headers/GameShape.hpp"
#include "../headers/GameScene.hpp"
#include "../headers/SceneControl.hpp"

GameObjects::GameShape& GameObjects::GameShape::setZIndex(unsigned int zIndex) {
	this->zIndex = zIndex;
	SceneControl::currentScene().setProperty<void*>("ResortElements", nullptr);
	return *this;
}
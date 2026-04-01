#include "../headers/GameRectangle.hpp"
#include "../headers/GameWindow.hpp"

using namespace GameObjects;

bool GameRectangle::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GameRectangle::draw() {
	window.draw(*this);
}
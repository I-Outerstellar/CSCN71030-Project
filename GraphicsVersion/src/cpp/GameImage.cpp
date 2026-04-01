#include "../headers/GameImage.hpp"
#include "../headers/GameWindow.hpp"

using namespace GameObjects;

bool GameImage::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GameImage::draw() {
	window.draw(*this);
}
#include "../headers/GameCircle.hpp"
#include "../headers/GameWindow.hpp"

using namespace GameObjects;

bool GameCircle::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GameCircle::draw() {
	window.draw(*this);
}
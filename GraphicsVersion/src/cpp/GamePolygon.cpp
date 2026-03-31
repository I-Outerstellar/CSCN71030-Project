#include "../headers/GamePolygon.hpp"
#include "../headers/GameWindow.hpp"

using namespace GameObjects;

bool GamePolygon::intersects(sf::Shape& shape) {
	return this->getGlobalBounds().findIntersection(shape.getGlobalBounds()).has_value();
}

void GamePolygon::draw() {
	window.draw(*this);
}
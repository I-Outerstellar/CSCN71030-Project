#include "../headers/RectangleButton.hpp"
#include "../headers/GameWindow.hpp"

using namespace GameObjects;

void RectangleButton::clickEvent(sf::Mouse::Button mouseButton) {
	if (this->pressed || !this->active) return;
	if (!this->mouseHovering)
		return;
	this->pressed = true;
	if (onClick != nullptr)
		onClick(mouseButton);
}

void RectangleButton::clickReleaseEvent(sf::Mouse::Button mouseButton) {
	if (!this->pressed) return;
	this->pressed = false;
	if (onClickRelease != nullptr)
		onClickRelease(mouseButton);
}

void RectangleButton::mouseMovementEvent(sf::Vector2f mousePosition, sf::Vector2i mouseDelta) {
	if (this->getGlobalBounds().contains(mousePosition))
		mouseHovering = true;
	else
		mouseHovering = false;
	if (this->onMouseMovement != nullptr)
		this->onMouseMovement(mousePosition, mouseDelta);
}

void RectangleButton::draw() {
	window.draw(*this);
}
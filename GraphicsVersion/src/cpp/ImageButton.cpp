#include "../headers/ImageButton.hpp"
#include "../headers/GameWindow.hpp"

using namespace GameObjects;

void ImageButton::clickEvent(sf::Mouse::Button mouseButton) {
	if (this->pressed || !this->active) return;
	if (!this->mouseHovering)
		return;
	this->pressed = true;
	if (onClick != nullptr)
		onClick(mouseButton);
}

void ImageButton::clickReleaseEvent(sf::Mouse::Button mouseButton) {
	if (!this->pressed) return;
	this->pressed = false;
	if (onClickRelease != nullptr)
		onClickRelease(mouseButton);
}

void ImageButton::mouseMovementEvent(sf::Vector2f mousePosition, sf::Vector2i mouseDelta) {
	if (this->getGlobalBounds().contains(mousePosition))
		mouseHovering = true;
	else
		mouseHovering = false;
	if (this->onMouseMovement != nullptr)
		this->onMouseMovement(mousePosition, mouseDelta);
}

void ImageButton::draw() {
	window.draw(*this);
}
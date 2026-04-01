#include "../headers/TextButton.hpp"
#include "../headers/GameWindow.hpp"

using namespace GameObjects;

void TextButton::changeText(std::string text) {
	this->text.setString(text);
	this->draw();
}

void TextButton::clickEvent(sf::Mouse::Button mouseButton) {
	if (this->pressed || !this->active) return;
	if (!this->mouseHovering)
		return;
	this->pressed = true;
	if (onClick != nullptr)
		onClick(mouseButton);
}

void TextButton::clickReleaseEvent(sf::Mouse::Button mouseButton) {
	if (!this->pressed) return;
	this->pressed = false;
	if (onClickRelease != nullptr)
		onClickRelease(mouseButton);
}

void TextButton::mouseMovementEvent(sf::Vector2f mousePosition, sf::Vector2i mouseDelta) {
	if (this->getGlobalBounds().contains(mousePosition))
		mouseHovering = true;
	else 
		mouseHovering = false;
	if (this->onMouseMovement != nullptr)
		this->onMouseMovement(mousePosition, mouseDelta);
}

void TextButton::draw() {
	window.draw(*this);
	auto shiftX = text.getLocalBounds().size.x / 2;
	auto shiftY = text.getLocalBounds().size.y / 2;
	text.setPosition(this->getGeometricCenter() - sf::Vector2f(shiftX, shiftY));
	window.draw(this->text);
}
#include "../headers/StateControl.hpp"
#include "../headers/StateData.hpp"
#include <thread>
#include <chrono>
#include <atomic>

/* HELPERS */

static bool& accessKey(sf::Keyboard::Scancode key) {
	return StateData::keysActivated.at(StateControl::scancodeToInt(key));
}

static bool& accessMouseButton(sf::Mouse::Button mouseButton) {
	return StateData::mouseButtonsActivated.at(StateControl::mouseButtonToInt(mouseButton));
}

/* ACCESSORS */

int StateControl::scancodeToInt(sf::Keyboard::Scancode key) {
	return static_cast<int>(key) + 1;
}

int StateControl::mouseButtonToInt(sf::Mouse::Button mouseButton) {
	return static_cast<int>(mouseButton);
}

bool StateControl::Accessors::getKeyPressed(sf::Keyboard::Scancode key) {
	return accessKey(key);
}

bool StateControl::Accessors::getMouseButtonPressed(sf::Mouse::Button mouseButton) {
	return accessMouseButton(mouseButton);
}

bool StateControl::Accessors::canAcceptInput() {
	return StateData::acceptingInput.load();
}

/* MODIFIERS */

void StateControl::Modifiers::setKeyPressed(sf::Keyboard::Scancode key, bool state) {
	accessKey(key) = state;
}

void StateControl::Modifiers::setMouseButtonPressed(sf::Mouse::Button mouseButton, bool state) {
	accessMouseButton(mouseButton) = state;
}

void StateControl::Modifiers::disableInputAccepting(unsigned int milliseconds) {
	if (!StateData::acceptingInput) return;
	std::thread t([milliseconds]() {
		StateData::acceptingInput = false;
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
		StateData::acceptingInput = true;
	});
	t.detach();
}
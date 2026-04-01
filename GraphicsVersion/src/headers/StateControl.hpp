#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

namespace StateControl {

	/// <summary>
	/// Converts a key scancode to an integer. 
	/// Use this instead of static casting.
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	int scancodeToInt(sf::Keyboard::Scancode key);

	/// <summary>
	/// Converts a mouse button to an integer. 
	/// Use this instead of static casting.
	/// </summary>
	/// <param name="mouseButton"></param>
	/// <returns></returns>
	int mouseButtonToInt(sf::Mouse::Button mouseButton);

	/// <summary>
	/// Getters/Accessor methods for the current game states
	/// </summary>
	namespace Accessors {
		/// <summary>
		/// Gets the current pressed state of a key.
		/// </summary>
		/// <param name="key"></param>
		/// <returns>True if it is pressed, false if not.</returns>
		bool getKeyPressed(sf::Keyboard::Scancode key);

		/// <summary>
		/// Gets the current pressed state of a mouse button.
		/// </summary>
		/// <param name="mouseButton"></param>
		/// <returns>True if it is pressed, false if not.</returns>
		bool getMouseButtonPressed(sf::Mouse::Button mouseButton);

		/// <summary>
		/// Checks if the window is able to accept input.
		/// </summary>
		/// <returns>True if input can be accepted, false if not.</returns>
		bool canAcceptInput();
	}
	
	/// <summary>
	/// Setters/Modifiers for the current game states
	/// </summary>
	namespace Modifiers {
		/// <summary>
		/// Sets the pressed state of a key. True if pressed, false if released.
		/// </summary>
		/// <param name="key"></param>
		/// <param name="state"></param>
		void setKeyPressed(sf::Keyboard::Scancode key, bool state);

		/// <summary>
		/// Sets the pressed state of a mouse button. True if pressed, false if released.
		/// </summary>
		/// <param name="mouseButton"></param>
		/// <param name="state"></param>
		void setMouseButtonPressed(sf::Mouse::Button mouseButton, bool state);

		/// <summary>
		/// Disables the window's ability to accept input for the specified time.
		/// </summary>
		/// <param name="milliseconds"></param>
		void disableInputAccepting(unsigned int milliseconds);
	}

}

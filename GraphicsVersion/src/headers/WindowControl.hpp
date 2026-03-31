#pragma once
#include <SFML/Graphics.hpp>

namespace WindowControl {
	/// <summary>
	/// Begins the drawing and input loop for the window.
	/// </summary>
	/// <param name="title"></param>
	/// <param name="windowState"></param>
	/// <param name="fps"></param>
	void beginWindowLoop(const std::string title, sf::State windowState = sf::State::Windowed, unsigned int fps = 60);

	/// <summary>
	/// Get the window in a modifiable state. Only use this if necessary.
	/// </summary>
	/// <returns></returns>
	sf::Window& gameWindow();
}

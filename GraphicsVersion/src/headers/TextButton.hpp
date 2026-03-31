#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "TextImplement.hpp"
#include "GameButton.hpp"

namespace GameObjects {

	/// <summary>
	/// A class that represents a textbox button in the game.
	/// </summary>
	class TextButton : public sf::RectangleShape, public TextImplement, public GameButton {
	protected:
		/// <summary>
		/// Required constructor for the factory method.
		/// </summary>
		/// <param name="text"></param>
		/// <param name="zIndex"></param>
		/// <param name="characterSize"></param>
		TextButton(sf::Text text, unsigned int zIndex = 0, unsigned int characterSize = 30) :
			TextImplement(text), sf::RectangleShape(), GameButton(zIndex)
		{
			text.setCharacterSize(characterSize);
		}
	public:

		/// <summary>
		/// The method required to listen for a click
		/// </summary>
		virtual void clickEvent(sf::Mouse::Button mouseButton) override;

		/// <summary>
		/// The method required to listen to a click release
		/// </summary>
		virtual void clickReleaseEvent(sf::Mouse::Button mouseButton) override;

		/// <summary>
		/// The method required to listen to mouse movement
		/// </summary>
		virtual void mouseMovementEvent(sf::Vector2f mousePosition, sf::Vector2i mouseDelta) override;

		/// <summary>
		/// Change the text of the button.
		/// </summary>
		/// <param name="text"></param>
		virtual void changeText(std::string text) override;

		/// <summary>
		/// Draws the button.
		/// </summary>
		virtual void draw() override;

		virtual ~TextButton() = default;
	};

}
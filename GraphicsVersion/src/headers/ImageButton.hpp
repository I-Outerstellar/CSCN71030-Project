#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "GameButton.hpp"

namespace GameObjects {

	class ImageButton : public sf::Sprite, public GameButton {
	protected:
		/// <summary>
		/// Required constructor for the factory method.
		/// </summary>
		/// <param name="texture"></param>
		/// <param name="zIndex"></param>
		ImageButton(sf::Texture& texture, unsigned int zIndex = 0) :
			sf::Sprite(texture), GameButton(zIndex) {}

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
		/// Draws the button.
		/// </summary>
		virtual void draw() override;

		virtual ~ImageButton() = default;
	};

}
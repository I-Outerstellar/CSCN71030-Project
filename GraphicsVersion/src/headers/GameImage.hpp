#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "GameShape.hpp"

namespace GameObjects {

	/// <summary>
	/// Class that represents an image in the game, with a rectangular form.
	/// </summary>
	class GameImage : public sf::Sprite, public GameShape {
	protected:
		/// <summary>
		/// Required constructor for the factory method.
		/// </summary>
		/// <param name="texture"></param>
		/// <param name="zIndex"></param>
		GameImage(sf::Texture& texture, unsigned int zIndex = 0) :
			sf::Sprite(texture), GameShape(zIndex) {}

	public:

		/// <summary>
		/// Checks if this shape intersects another shape.
		/// </summary>
		/// <param name="shape"></param>
		/// <returns></returns>
		virtual bool intersects(sf::Shape& shape) override;

		/// <summary>
		/// Draws the shape.
		/// </summary>
		virtual void draw() override;

		virtual ~GameImage() = default;
	};

}
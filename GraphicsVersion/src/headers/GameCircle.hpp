#pragma once
#include "GameShape.hpp"
#include <memory>

namespace GameObjects {

	/// <summary>
	/// Class that represents a circle in the game.
	/// </summary>
	class GameCircle : public GameShape, public sf::CircleShape {
	protected:
		/// <summary>
		/// Required constructor for the factory method
		/// </summary>
		/// <param name="zIndex"></param>
		GameCircle(unsigned int zIndex = 0) : GameShape(zIndex) {}
	public:

		/// <summary>
		/// Returns if this shape and the given shape intersects or not.
		/// </summary>
		/// <param name="shape"></param>
		/// <returns></returns>
		virtual bool intersects(sf::Shape& shape) override;

		/// <summary>
		/// Draws the shape.
		/// </summary>
		virtual void draw() override;

		virtual ~GameCircle() = default;
	};

}
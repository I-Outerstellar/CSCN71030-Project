#pragma once
#include "GameShape.hpp"
#include <memory>

namespace GameObjects {

	/// <summary>
	/// Class that represents a rectangle in the game.
	/// </summary>
	class GameRectangle : public GameShape, public sf::RectangleShape {
	protected:
		/// <summary>
		/// Required constructor for the factory method
		/// </summary>
		/// <param name="zIndex"></param>
		GameRectangle(unsigned int zIndex = 0) : GameShape(zIndex) {}
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

		virtual ~GameRectangle() = default;
	};

}
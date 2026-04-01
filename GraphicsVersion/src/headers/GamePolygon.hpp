#pragma once
#include <SFML/Graphics.hpp>
#include "GameShape.hpp"

namespace GameObjects {

	/// <summary>
	/// Class that represents a customized polygon in the game.
	/// </summary>
	class GamePolygon : public GameShape, public sf::ConvexShape {
	protected:
		/// <summary>
		/// Required constructor for the factory method
		/// </summary>
		/// <param name="zIndex"></param>
		GamePolygon(unsigned int zIndex = 0) : GameShape(zIndex) {}
	public:

		/// <summary>
		/// Checks if this shape is intersecting another shape.
		/// </summary>
		/// <param name="shape"></param>
		/// <returns></returns>
		virtual bool intersects(sf::Shape& shape) override;

		/// <summary>
		/// Draws the shape.
		/// </summary>
		virtual void draw() override;

		virtual ~GamePolygon() = default;
	};

}
#pragma once
#include <memory>
#include <utility>
#include "SFML/Graphics.hpp"
#include "GameDrawable.hpp"

namespace GameObjects {

	/// <summary>
	/// Interface for creating a game shape.
	/// </summary>
	class GameShape : public GameDrawable {
	protected:
		using GameDrawable::GameDrawable;

	public:

		/// <summary>
		/// Creates a game shape of the type specified, limited to shapes inheriting GameShape.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="...args"></param>
		/// <returns>A shared pointer to the shape created.</returns>
		template<std::derived_from<GameShape> T, typename... Args>
		static std::shared_ptr<T> create(Args&&... args) {
			struct GameShapeAccess : public T {
				GameShapeAccess(Args&&... args) : T(std::forward<Args>(args)...) {}
			};

			std::shared_ptr<GameShape> shape = std::make_shared<GameShapeAccess>(std::forward<Args>(args)...);
			return std::static_pointer_cast<T>(shape);
		}

		/// <summary>
		/// Returns if this shape and the given shape intersects or not.
		/// This method is the same among all shapes, I just can't define it here. 
		/// </summary>
		/// <param name="shape"></param>
		/// <returns></returns>
		virtual bool intersects(sf::Shape& shape) = 0;

		/// <summary>
		/// Sets the Z-Index of the shape.
		/// </summary>
		/// <param name="zIndex"></param>
		/// <returns></returns>
		GameShape& setZIndex(unsigned int zIndex);

		virtual ~GameShape() = default;
	};

}
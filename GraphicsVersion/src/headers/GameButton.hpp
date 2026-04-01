#pragma once
#include <functional>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <utility>
#include "GameDrawable.hpp"

namespace GameObjects {

	/// <summary>
	/// A class that represents a rectangular button in the game.
	/// </summary>
	class GameButton : public GameDrawable {
	protected:
		/// <summary>
		/// Determines if the button is pressed down or not.
		/// </summary>
		bool pressed = false;
		
		/// <summary>
		/// Determines if the mouse is hovering over the button or not.
		/// </summary>
		bool mouseHovering = false;

		using GameDrawable::GameDrawable;
	public:
		/*Variables*/

		/// <summary>
		/// Determines if the button can be used or not.
		/// </summary>
		bool active = true;

		/// <summary>
		/// Definable method for on click and on click release
		/// </summary>
		std::function<void(sf::Mouse::Button)> onClick, onClickRelease;

		/// <summary>
		/// Definable method for the mouse moving. Useful to detect if the button is being hovered over.
		/// </summary>
		std::function<void(sf::Vector2f mousePosition, sf::Vector2i mouseDelta)> onMouseMovement;


		/*Methods*/

		/// <summary>
		/// Creates a game button of the type specified, limited to buttons inheriting GameButton.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="...args"></param>
		/// <returns>A shared pointer to the button created.</returns>
		template<std::derived_from<GameButton> T, typename... Args>
		static std::shared_ptr<T> create(Args&&... args) {
			struct GameButtonAccess : public T {
				GameButtonAccess(Args&&... args) : T(std::forward<Args>(args)...) {}
			};

			std::shared_ptr<GameButton> button = std::make_shared<GameButtonAccess>(std::forward<Args>(args)...);
			return std::static_pointer_cast<T>(button);
		}

		/// <summary>
		/// Returns if the button is pressed
		/// </summary>
		/// <returns>True if the button is pressed, false if not</returns>
		virtual bool isPressed() { return this->pressed; }

		/// <summary>
		/// Returns if the mouse is hovering over the button
		/// </summary>
		/// <returns>True if the mouse is hovering over the button, false if not</returns>
		virtual bool isMouseHovering() { return this->mouseHovering; }

		/// <summary>
		/// The method required to listen for a click
		/// </summary>
		virtual void clickEvent(sf::Mouse::Button mouseButton) = 0;

		/// <summary>
		/// The method required to listen to a click release
		/// </summary>
		virtual void clickReleaseEvent(sf::Mouse::Button mouseButton) = 0;

		/// <summary>
		/// The method required to listen to mouse movement
		/// </summary>
		virtual void mouseMovementEvent(sf::Vector2f mousePosition, sf::Vector2i mouseDelta) = 0;

		/// <summary>
		/// Sets the Z-Index of the button.
		/// </summary>
		/// <param name="zIndex"></param>
		/// <returns></returns>
		GameButton& setZIndex(unsigned int zIndex);

		virtual ~GameButton() = default;
	};

}
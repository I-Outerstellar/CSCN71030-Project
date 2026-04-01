#pragma once
#include <SFML/Graphics/Text.hpp>

namespace GameObjects {

	class TextImplement {
	protected:

	public:
		sf::Text text;

		/// <summary>
		/// Required constructor for any game objects with text.
		/// </summary>
		/// <param name="text"></param>
		TextImplement(const sf::Text& text) : text(text) {}

		virtual void changeText(std::string text) = 0;
		virtual ~TextImplement() = default;
	};

}
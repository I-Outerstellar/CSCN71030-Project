#pragma once

namespace SlidingTilesEnums {
	/// <summary>
	/// Enums that represent the difficulty of Sliding Tiles. 
	/// The values associated to the enums are the board size.
	/// </summary>
	enum class Difficulty {
		EASY = 3,
		MEDIUM = 4,
		HARD = 6,
		INSANE = 9
	};

	/// <summary>
	/// Enums that represent a direction that a slide can occur.
	/// </summary>
	enum class Direction {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
}
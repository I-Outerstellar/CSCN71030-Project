////////////////////////////////////////////////////////////////////////////////
///
/// @file		SlidingTilesEnums.hpp
/// @brief		File containing a namespace with enum classes for a Sliding Tiles game.
/// @details	This file contains a namespace with enum classes that represent the difficulty
///				of a Sliding Tiles game and the directions which a slide can occur.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
///
////////////////////////////////////////////////////////////////////////////////
#pragma once

/// @brief	 Namespace containing enum classes for a Sliding Tiles game.
/// @details Namespace containing enum classes that represent the difficulty of a Sliiding
///			 Tiles game and the directions which a slide can occur.
/// @author  Rajdeep Chowdhury
/// @date    8.04.2026
namespace SlidingTilesEnums {
	/// @brief   Enum class containing difficulties for a Sliding Tiles game.
	/// @details Enum class containing difficulties for a Sliding Tiles game. The integers of
	///			 each enum represent the size of board they produce.
	/// @author  Rajdeep Chowdhury
	/// @date    8.04.2026
	enum class Difficulty {
		/// @brief	 EASY Difficulty. Has a board size of 3.
		/// @details The easy difficulty for Sliding Tiles. Has a board size of 3, meaning
		///			 a 3x3 board is produced.
		EASY = 3,

		/// @brief	 MEDIUM Difficulty. Has a board size of 4.
		/// @details The medium difficulty for Sliding Tiles. Has a board size of 4, meaning
		///			 a 4x4 board is produced.
		MEDIUM = 4,

		/// @brief	 HARD Difficulty. Has a board size of 6.
		/// @details The hard difficulty for Sliding Tiles. Has a board size of 6, meaning
		///			 a 6x6 board is produced.
		HARD = 6,

		/// @brief	 INSANE Difficulty. Has a board size of 9.
		/// @details The insane difficulty for Sliding Tiles. Has a board size of 9, meaning
		///			 a 9x9 board is produced.
		INSANE = 9
	};

	/// @brief   Enum class containing directions that a slide can occur.
	/// @details Enum class containing the four directions that a slide can be performed in. It is used
	///			 in the context of the empty tile sliding to an adjacent filled tile, rather that the vice versa.
	/// @author  Rajdeep Chowdhury
	/// @date    8.04.2026
	enum class Direction {
		/// @brief UP Direction.
		/// @details Enum used to slide the empty tile up.
		UP,

		/// @brief DOWN Direction.
		/// @details Enum used to slide the empty tile down.
		DOWN,

		/// @brief LEFT Direction.
		/// @details Enum used to slide the empty tile left.
		LEFT,

		/// @brief RIGHT Direction.
		/// @details Enum used to slide the empty tile right.
		RIGHT
	};
}
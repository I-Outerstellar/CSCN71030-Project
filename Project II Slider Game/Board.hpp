#pragma once
#include <vector>
#include "SlidingTilesEnums.hpp"

/// <summary>
/// A class that represents the square board for a game.
/// </summary>
class Board {
protected:
	std::vector<std::vector<size_t>> board{};

public:
	Board() noexcept;

	/// <summary>
	/// Constructor for a board.
	/// </summary>
	/// <param name="difficulty"></param>
	Board(SlidingTilesEnums::Difficulty difficulty) noexcept;

	/// <summary>
	/// Checks if the board has an empty column, meaning one of the sizes of the columns is 0. 
	/// Also checks for if the board itself has no columns.
	/// </summary>
	/// <returns>True if a column or the board itself is empty, false if not.</returns>
	bool isColumnEmpty();

	/// <summary>
	/// Checks if a board index can be accessed.
	/// </summary>
	/// <param name="column"></param>
	/// <param name="row"></param>
	/// <returns>True if access is granted, false if not.</returns>
	bool canAccess(size_t column, size_t row) const noexcept;

	/// <summary>
	/// Accesses an integer in the board.
	/// </summary>
	/// <param name="column"></param>
	/// <param name="row"></param>
	/// <returns>Reference to an integer on the board.</returns>
	int& access(size_t column, size_t row) const;
};
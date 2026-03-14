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
	/// Checks if the board has an empty row, meaning one of the sizes of the row is 0. 
	/// Also checks for if the board itself has no row.
	/// </summary>
	/// <returns>True if a row or the board itself is empty, false if not.</returns>
	bool hasEmptyRow() const noexcept;

	/// <summary>
	/// Checks if a board index can be accessed. Indexing starts at 0.
	/// </summary>
	/// <param name="row"></param>
	/// <param name="column"></param>
	/// <returns>True if index exists, false if not.</returns>
	bool canAccess(size_t row, size_t column) const noexcept;

	/// <summary>
	/// Checks if a board row can be accessed. Indexing starts at 0.
	/// </summary>
	/// <param name="row"></param>
	/// <returns>True if row exists, false if not.</returns>
	bool canAccess(size_t row) const noexcept;

	/// <summary>
	/// Accesses an integer in the board. Indexing starts at 0.
	/// </summary>
	/// <param name="row"></param>
	/// <param name="column"></param>
	/// <returns>Reference to an integer on the board.</returns>
	size_t& access(size_t row, size_t column);

	/// <summary>
	/// Accessses a row of the board. Indexing starts at 0.
	/// </summary>
	/// <param name="row"></param>
	/// <returns>A reference to a row vector of the board.</returns>
	std::vector<size_t>& access(size_t row);
};
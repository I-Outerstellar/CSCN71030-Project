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
	/// Returns if the board is initialized, meaning if it has one or more spaces.
	/// </summary>
	/// <returns>True if initialized, false if not.</returns>
	bool isInitialized();

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
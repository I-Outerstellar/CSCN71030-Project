////////////////////////////////////////////////////////////////////////////////
///
/// @file		Board.hpp
/// @brief		File containing a @c Board class.
/// @details	This file contains a class representing a board for any game, with
///				the declaration of its method and attributes initialized.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		Board.cpp
///
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <vector>

//Forward declaration

namespace SlidingTilesEnums {
	enum class Difficulty;
}

/// @brief   A class that represents a board.
/// @details A class that represents a board for any game that can be represented by numbered tiles.
/// @author  Rajdeep Chowdhury
/// @date    8.04.2026
class Board {
protected:
	/// @brief	 The data representation of the board.
	/// @details The vector of vectors of size_t which represents a board.
	std::vector<std::vector<size_t>> board{};

public:
	/// @brief   @c Board object constructor.
	/// @details The default constructor for the @c Board that creates an empty, sizeless board.
	/// @author  Rajdeep Chowdhury
	/// @date    8.04.2026
	Board() noexcept;

	/// @brief		@c Board object constructor.
	/// @details	The parameterized constructor for the @c Board that creates a board based 
	///				on the difficulty passed through for Sliding Tiles.
	/// @param[in]	difficulty The difficulty of the Sliding Tiles game desired.
	/// @author		Raj Bahadur Bhat
	/// @date		8.04.2026
	/// 
	/// @see		SlidingTilesEnums
	Board(SlidingTilesEnums::Difficulty difficulty) noexcept;

	/// @brief		Checks if the board has an empty row or is empty.
	/// @details	Checks if one of the vector sizes of a board row is 0. 
	///				Also checks for if the board itself has no rows.
	/// @retval		true If an empty row exists.
	/// @retval		true If the board itself is empty.
	/// @retval		false If neither condition is true.
	/// @author		Rajdeep Chowdhury
	/// @date		8.04.2026
	bool hasEmptyRow() const noexcept;

	/// @brief		Checks if a @c Board index can be accessed. Index starts at 0.
	/// @details	Checks if a @c Board index can exist in accordance to the size of the vectors 
	///				representing the board. Index starts at 0.
	/// @param[in]	row	The row of the board being accessed.
	/// @param[in]	column The coloum of the board being accessed.
	/// @retval		true If the index exists.
	/// @retval		false If the index does not exist.
	/// @author		Rajdeep Chowdhury
	/// @date		8.04.2026
	bool canAccess(size_t row, size_t column) const noexcept;

	/// @brief		Checks if a @c Board row can be accessed. Index starts at 0.
	/// @details	Checks if a @c Board row can exist in accordance to the size of the vector 
	///				representing the board rows. Index starts at 0.
	/// @param[in]	row The row of the board being accessed.
	/// @retval		true If the row exists.     
	/// @retval		false If the row does not exist.
	/// @author		Rajdeep Chowdhury
	/// @date		8.04.2026
	bool canAccess(size_t row) const noexcept;

	/// @brief		Accesses an integer in the board. Indexing starts at 0.
	/// @details	Returns a reference to the size_t integer at the specified 
	///				@p row and @p column index.
	/// @param[in]	row The row of the board being accessed
	/// @param[in]	column The column of the board being accessed.
	/// @return		A reference to the size_t integer on the board.
	/// @throw		std::out_of_range If the row or column being accessed does not exist.
	/// @author		Rajdeep Chowdhury
	/// @date		8.04.2026
	/// 
	/// @note		The user should use the @ref canAccess(size_t, size_t) method before
	///				using this method to avoid the exception being thrown.
	/// @see		canAccess(size_t, size_t)
	size_t& access(size_t row, size_t column);

	/// @brief		Accesses a row in the board. Indexing starts at 0.
	/// @details	Returns a reference to the size_t row vector at the specified 
	///				@p row index.
	/// @param[in]	row The row of the board being accessed
	/// @return		A reference to the row vector on the board.
	/// @throw		std::out_of_range If the row being accessed does not exist.
	/// @author		Rajdeep Chowdhury
	/// @date		8.04.2026
	/// 
	/// @note		The user should use the @ref canAccess(size_t) method before
	///				using this method to avoid the exception being thrown.
	/// @see		canAccess(size_t)
	std::vector<size_t>& access(size_t row);
};
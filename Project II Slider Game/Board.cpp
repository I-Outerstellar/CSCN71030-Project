////////////////////////////////////////////////////////////////////////////////
///
/// @file		Board.cpp
/// @brief		File containing the initialization of all @ref Board methods.
/// @details	This file contains the initialization of all @ref Board methods found in
///				@ref Board.hpp.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		Board.hpp
///
////////////////////////////////////////////////////////////////////////////////
#include "Board.hpp"

Board::Board() noexcept {}

Board::Board(SlidingTilesEnums::Difficulty difficulty) noexcept {
	int size = static_cast <int> (difficulty); //Convert the enum into the board size

	//Build the board
	board.resize(size);
	int counter = 1;
	for (int col = 0; col < size; col++) {
		board.at(col).resize(size);

		for (int row = 0; row < size; row++) {
			board.at(col).at(row) = counter;
			counter++;
		}
	}
}

bool Board::hasEmptyRow() const noexcept {
	if (this->board.size() <= 0) return true; //Check if board itself is empty
	for (int i = 0; i < board.size(); i++) { //Check each row for an empty row
		if (board.at(i).size() <= 0) return true;
	}
	return false;
}

std::vector<size_t>& Board::access(size_t row) {
	return this->board.at(row);
}

size_t& Board::access(size_t row, size_t column) {
	return this->access(row).at(column);
}

bool Board::canAccess(size_t row) const noexcept {
	return (row >= 0 && row < this->board.size());
}

bool Board::canAccess(size_t row, size_t column) const noexcept {
	if (!canAccess(row)) return false;
	size_t size = this->board.at(row).size();
	return (column >= 0 && column < size);
}
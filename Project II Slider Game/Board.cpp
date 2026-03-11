#include "Board.hpp"

Board::Board() {}

bool Board::hasEmptyColumn() const {
	if (this->board.size() <= 0) return false;
	for (int i = 0; i < board.size(); i++) {
		if (board.at(i).size() <= 0) return false;
	}
	return true;
}

std::vector<size_t>& Board::access(size_t column) {
	return this->board.at(column);
}

size_t& Board::access(size_t column, size_t row) {
	return this->access(column).at(row);
}

bool Board::canAccess(size_t column) const {
	return (column >= 0 && column < this->board.size());
}

bool Board::canAccess(size_t column, size_t row) const {
	if (!canAccess(column)) return false;
	size_t size = this->board.at(column).size();
	return (row >= 0 && row < size);
}
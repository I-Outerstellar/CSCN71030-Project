#include "Board.hpp"

Board::Board() {}

//Constructors for board difficulty
Board::Board(SlidingTilesEnums::Difficulty difficulty) noexcept {
    int size = static_cast <int> (difficulty);

    board.resize(size);

    int counter = 1;

    for (int col = 0; col < size; col++) {
        board.at(col).resize(size);

        for (int row = 0; row < size; row++) {
            board.at(col).at(row) = counter;
            counter++;
        }
    }

    board.at(size - 1).at(size - 1) = 0;
}

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
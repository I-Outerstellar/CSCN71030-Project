#include "BoardMock.hpp"

std::vector<std::vector<size_t>>& BoardMock::accessBoard() {
	return this->board;
}
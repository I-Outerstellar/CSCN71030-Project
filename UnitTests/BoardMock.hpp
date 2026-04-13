#pragma once
#include "../Project II Slider Game/Board.hpp"

class BoardMock : public Board {
public:
	using Board::Board;

	std::vector<std::vector<size_t>>& accessBoard();
};
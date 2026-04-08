////////////////////////////////////////////////////////////////////////////////
///
/// @file		UserFunctionsHelpers.hpp
/// @brief		File containing namespace of declared helper functions and a constant expression for @ref UserFunctions.
/// @details	This file contains a namespace of declared helper functions that the functions of @ref UserFunctions use.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		UserFunctionsHelpers.cpp
/// @see		UserFunctions
///
////////////////////////////////////////////////////////////////////////////////
#pragma once

//Forward Declaration
namespace SlidingTilesEnums {
	enum class Direction;
}

namespace UserFunctionsHelpers {
	void startGame();

	void trySlide(SlidingTilesEnums::Direction direction);

	void printBoard();

	void printLeaderboard();

	bool continueGame();
}
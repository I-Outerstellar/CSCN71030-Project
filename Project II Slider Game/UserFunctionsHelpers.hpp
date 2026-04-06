/*******************************************************************************
 *
 *  @file      UserFunctionsHelper.hpp
 *  @brief     
 *  @details   ~
 *  @author    Rajdeep Chowdhury
 *  @date      1.04.2026
 *
 ******************************************************************************/
#pragma once
#include "SlidingTilesEnums.hpp"

namespace UserFunctionsHelpers {
	void startGame();

	void trySlide(SlidingTilesEnums::Direction direction);

	void printBoard();

	void printLeaderboard();

	bool continueGame();
}
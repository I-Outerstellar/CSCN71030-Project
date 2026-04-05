/*******************************************************************************
 *
 *  @file      SlidingTilesFunctionsHelpers.hpp
 *  @brief     
 *  @details   ~
 *  @author    Rajdeep Chowdhury
 *  @date      1.04.2026
 *
 ******************************************************************************/
#pragma once
#include "SlidingTilesEnums.hpp"

namespace SlidingTilesFunctionsHelpers {
	constexpr unsigned short LEADERBOARD_SIZE = 10;

	SlidingTilesEnums::Direction getRandomDirection();

	SlidingTilesEnums::Direction getOpposite(SlidingTilesEnums::Direction dir);
}
////////////////////////////////////////////////////////////////////////////////
///
/// @file		UserFunctions.hpp
/// @brief     
/// @details	~
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		UserFunctions.cpp
///
////////////////////////////////////////////////////////////////////////////////
#pragma once

/// @brief   Namespace containing functions that the user interacts with.
/// @details Namespace containing functions which turn user input into output. It is the module
///			 that users directly interact with.
/// @author  Rajdeep Chowdhury
/// @date    8.04.2026
namespace UserFunctions {
	/// @brief   
	/// @details ~
	/// @retval	 true If quit is not selected.
	/// @retval	 false If quit is selected.
	/// @author  Rajdeep Chowdhury
	/// @date    8.04.2026
	bool selectDifficulty();

	/// @brief   
	/// @details ~
	/// @retval	 true If quit is not selected or the game is not over.
	/// @retval	 false If quit is selected or the game is over.
	/// @author  Rajdeep Chowdhury
	/// @date    8.04.2026
	bool performSlide();
}
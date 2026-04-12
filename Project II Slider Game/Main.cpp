////////////////////////////////////////////////////////////////////////////////
///
/// @file		Main.cpp
/// @brief		Main file where the program is executed.
/// @details	This file is the main file. It is where the functions that start the program are called.
/// @author		Rajdeep Chowdhury
/// @date		8.04.2026
/// 
/// @see		UserFunctions.hpp
///
////////////////////////////////////////////////////////////////////////////////
#include "UserFunctions.hpp"

/// @brief   Execute the program.
/// @details The main function that executes the program.
/// @return  Exit code.
/// @author  Rajdeep Chowdhury
/// @date    8.04.2026
int main() {
	while (UserFunctions::selectDifficulty()) {
		while (UserFunctions::performSlide());
	}
}
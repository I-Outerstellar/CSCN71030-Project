#pragma once
#include <atomic>
#include <array>

/*
	May be due for change
*/

namespace StateData {
	/// <summary>
	/// An array of all keys SFML supports and their state.
	/// </summary>
	extern std::array<bool, 147> keysActivated;

	/// <summary>
	/// An array of all mouse buttons SFML supports and their state.
	/// </summary>
	extern std::array<bool, 5> mouseButtonsActivated;

	/// <summary>
	/// A boolean that tells the window if input is allowed to be accepted or not.
	/// </summary>
	extern std::atomic<bool> acceptingInput;
}

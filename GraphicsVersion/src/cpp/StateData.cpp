#include "../headers/StateData.hpp"

/* VARIABLES */

std::array<bool, 147> StateData::keysActivated{};
std::array<bool, 5> StateData::mouseButtonsActivated{};
std::atomic<bool> StateData::acceptingInput = true;
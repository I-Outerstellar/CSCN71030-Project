#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <functional>

/// <summary>
/// The lambda functions required for event listening
/// </summary>
namespace EventListeners {
    /// <summary>
    /// Lambda function for when the window close event is called.
    /// </summary>
    extern const std::function<void(const sf::Event::Closed& event)> windowClosed;

    /// <summary>
    /// Lambda function for when a key is pressed.
    /// </summary>
    extern const std::function<void(const sf::Event::KeyPressed& keyPressed)> onKeyPressed;

    /// <summary>
    /// Lambda function for when a key is released.
    /// </summary>
    extern const std::function<void(const sf::Event::KeyReleased& keyPressed)> onKeyReleased;

    /// <summary>
    /// Lambda function for when the left, right, or middle mouse button is clicked.
    /// </summary>
    extern const std::function<void(const sf::Event::MouseButtonPressed& mouseClick)> onClick;

    /// <summary>
    /// Lambda function for when the left, right, or middle mouse button is released.
    /// </summary>
    extern const std::function<void(const sf::Event::MouseButtonReleased& mouseClickRelease)> onClickRelease;

    /// <summary>
    /// Lambda function for when the mouse is moved.
    /// </summary>
    extern const std::function<void(const sf::Event::MouseMovedRaw& mouseMovement)> onMouseMovement;
}


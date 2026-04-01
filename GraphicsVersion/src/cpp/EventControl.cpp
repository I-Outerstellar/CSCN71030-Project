#include "../headers/EventControl.hpp"
#include "../headers/GameButton.hpp"
#include "../headers/GameScene.hpp"
#include "../headers/SceneData.hpp"
#include "../headers/GameWindow.hpp"
#include "../headers/StateControl.hpp"

const std::function<void(const sf::Event::Closed& event)> EventListeners::windowClosed = [](const sf::Event::Closed& event) {
    window.close();
};

const std::function<void(const sf::Event::KeyPressed& keyPressed)> 
EventListeners::onKeyPressed = [](const sf::Event::KeyPressed& keyPressed) {
    using namespace sf::Keyboard;
    
    if (StateControl::Accessors::canAcceptInput() == true || keyPressed.scancode == sf::Keyboard::Scancode::Escape) {
        StateControl::Modifiers::setKeyPressed(keyPressed.scancode, true);
        std::function<void()> keyPressFunction = SceneStorage::currentScene->keyPressFunctions.at(StateControl::scancodeToInt(keyPressed.scancode));
        if (keyPressFunction != nullptr) keyPressFunction();
    }
};

const std::function<void(const sf::Event::KeyReleased& keyReleased)> 
EventListeners::onKeyReleased = [](const sf::Event::KeyReleased& keyReleased) {
    using namespace sf::Keyboard;

    StateControl::Modifiers::setKeyPressed(keyReleased.scancode, false);
    std::function<void()> keyReleaseFunction = SceneStorage::currentScene->keyReleaseFunctions.at(StateControl::scancodeToInt(keyReleased.scancode));
    if (keyReleaseFunction != nullptr) keyReleaseFunction();
};

const std::function<void(const sf::Event::MouseMovedRaw& mouseMovement)>
EventListeners::onMouseMovement = [](const sf::Event::MouseMovedRaw& mouseMovement) {
    for (auto& b : SceneStorage::currentScene->getSceneButtons()) {
        b->mouseMovementEvent(window.mapPixelToCoords(sf::Mouse::getPosition(window)), mouseMovement.delta);
    }
};

#pragma warning (push)
#pragma warning (disable : 4100)
const std::function<void(const sf::Event::MouseButtonPressed& mouseClick)> 
EventListeners::onClick = [](const sf::Event::MouseButtonPressed& mouseClick) {
    StateControl::Modifiers::setMouseButtonPressed(mouseClick.button, true);
    if (!StateControl::Accessors::canAcceptInput()) return;
    for (auto& b : SceneStorage::currentScene->getSceneButtons()) {
        b->clickEvent(mouseClick.button);
    }
};

const std::function<void(const sf::Event::MouseButtonReleased& mouseClickRelease)> 
EventListeners::onClickRelease = [](const sf::Event::MouseButtonReleased& mouseClickRelease) {
    StateControl::Modifiers::setMouseButtonPressed(mouseClickRelease.button, false);
    for (auto& b : SceneStorage::currentScene->getSceneButtons()) {
        b->clickReleaseEvent(mouseClickRelease.button);
    }
};
#pragma warning (pop)
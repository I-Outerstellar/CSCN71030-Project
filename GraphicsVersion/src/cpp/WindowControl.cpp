#include "../headers/GameWindow.hpp"
#include "../headers/WindowControl.hpp"
#include "../headers/SceneControl.hpp"
#include "../headers/GameScene.hpp"
#include "../headers/EventControl.hpp"

void WindowControl::beginWindowLoop(const std::string title, sf::State windowState, unsigned int fps) {
    window.create(sf::VideoMode::getDesktopMode(), title, windowState);
    window.setFramerateLimit(fps);

    while (window.isOpen())
    {
        window.handleEvents(EventListeners::onKeyPressed, EventListeners::onKeyReleased,
            EventListeners::onClick, EventListeners::onClickRelease, EventListeners::onMouseMovement,
            EventListeners::windowClosed);

        SceneControl::updateBeforeDraw();
        SceneControl::draw();
        SceneControl::updateAterDraw();
        
    }

}

sf::Window& WindowControl::gameWindow() {
    return window;
}
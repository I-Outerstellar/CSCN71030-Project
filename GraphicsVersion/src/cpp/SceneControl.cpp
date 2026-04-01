#include "../headers/SceneControl.hpp"
#include "../headers/GameButton.hpp"
#include "../headers/GameShape.hpp"
#include "../headers/GameScene.hpp"
#include "../headers/SceneData.hpp"
#include "../headers/GameWindow.hpp"

void SceneControl::updateBeforeDraw() {
    for (std::function<void()>* func : SceneStorage::currentScene->getBeforeDrawFunctions()) {
        if (func != nullptr && *func != nullptr) (*func)();
    }
    if (currentScene().hasProperty("ResortElements")) {
        currentScene().deleteProperty("ResortElements");
        sortElements(currentScene());
    }
}

void SceneControl::draw() {

    window.clear(SceneStorage::currentScene->backgroundColour);

    for (auto& s : SceneStorage::currentScene->getSceneShapes()) {
        if (s->visible)
            s->draw();
    }
    for (auto& b : SceneStorage::currentScene->getSceneButtons()) {
        if (b->visible)
            b->draw();
    }

    window.display();

}

void SceneControl::updateAterDraw() {
    for (std::function<void()>* func : SceneStorage::currentScene->getAfterDrawFunctions()) {
        if (func != nullptr && *func != nullptr) (*func)();
    }
}

GameObjects::GameScene& SceneControl::currentScene() {
    return *SceneStorage::currentScene;
}

void SceneControl::switchScene(GameObjects::GameScene& scene) {
    GameObjects::GameScene& beforeScene = *SceneStorage::currentScene;
    bool scene1Pass = true, scene2Pass = true;
    if (beforeScene.switchedFrom != nullptr) {
        scene1Pass = SceneStorage::currentScene->switchedFrom(scene);
    }
    if (scene.switchedTo != nullptr) {
        scene2Pass = scene.switchedTo(beforeScene);
    }
    if (scene1Pass && scene2Pass) {
        SceneStorage::currentScene = &scene;
        sortElements(currentScene());
    }
}

GameObjects::GameScene& SceneControl::sortElements(GameObjects::GameScene& scene) {
    scene.sortButtons();
    scene.sortShapes();
    return scene;
}
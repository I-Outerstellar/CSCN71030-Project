#include "../headers/SceneData.hpp"
#include "../headers/GameScene.hpp"

GameObjects::GameScene SceneStorage::defaultScene = GameObjects::GameScene();
GameObjects::GameScene* SceneStorage::currentScene = &defaultScene;
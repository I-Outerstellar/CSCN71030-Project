#pragma once
#include <vector>
#include <memory>

namespace GameObjects {
	class GameScene;
}

/// <summary>
/// Namespace that holds the currently used scene
/// </summary>
namespace SceneStorage {
	/// <summary>
	/// The scene that the program always starts at and will always exist.
	/// </summary>
	extern GameObjects::GameScene defaultScene;

	/// <summary>
	/// A pointer to the current scene being displayed and used.
	/// </summary>
	extern GameObjects::GameScene* currentScene;
}

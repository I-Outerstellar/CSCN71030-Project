#pragma once

namespace GameObjects {

	/// <summary>
	/// Implement for representing drawable game objects.
	/// </summary>
	class GameDrawable {
	protected:
		/// <summary>
		/// The zIndex of the drawwable, affecting what order it draws in
		/// </summary>
		unsigned int zIndex = 0;
	public:
		/*Variables*/

		/// <summary>
		/// Determines if the shape will be drawn or not.
		/// </summary>
		bool visible = true;

		GameDrawable(unsigned int zIndex) { this->zIndex = zIndex; }


		/*Methods*/

		/// <summary>
		/// Gets the Z-Index of the drawable object.
		/// </summary>
		/// <returns></returns>
		unsigned int getZIndex() const { return this->zIndex; }

		//Set Z-Index methods are in every direct descendant of this class

		/// <summary>
		/// Draws the game object.
		/// </summary>
		virtual void draw() = 0;
		virtual ~GameDrawable() = default;
		void operator=(GameDrawable drawable) = delete;
	};

}
# CSCN71030 Project

The goal is to create a slider-puzzle game that stores scores, measured in the amount of moves that occur, and then displays them on a leaderboard (or website if possible).

This group consists of Rajdeep, Fabio, and Raj.

## Minimum Viable Product

- The slider game has one difficulty (C++ or Java)
- Scores are stored locally in a text file
- A terminal command is used to display the local top scores

## Middle Viable Product

- The slider game has one difficulty (C++ or Java)
- Scores are submitted to a Python Flask backend using the HTTP protocol
- Scores are stored in a local SQLite database
- A website displays the unordered scores submitted (HTML, CSS, JavaScript), retrieved through HTTP

## Desired Product

- The slider game has more than one difficulty and is decently appealing to the eye (C++ or Java)
- Scores are submitted to a Python Flask backend using HTTP protocol
- Scores are stored in either a local SQLite database or server-hosted PostgreSQL database
- A website displays the leaderboard (HTML, CSS, JavaScript), retrieved through HTTP

##
##

# SFML Extension Framework Details

- Many game objects and controllers to control one global window, the only window that should be used

- Button support

- Scenes to switch between

- Z-Index of buttons and shapes that can be changed mid-execution

- Supports inheritence of game shapes and buttons



# Limitations

- Does not have a built-in way to size shapes relative to the screen size

- Buttons always draw over shapes

- Z-Indexes of shapes and buttons cannot be different between multiple scenes

- Cannot make a derived class from GameScene, unless you are only changing a method's behaviour instead of adding a new attribute/method. Please use its properties map instead to achieve similar behaviour.

- Works alongside SFML methods rather than using new, original ones (this project was not made to reinvent the wheel)


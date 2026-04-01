#include <SFML/Graphics.hpp>
#include "src/headers/WindowControl.hpp"
#include "include/GameControllers.hpp"
#include "include/GameObjects.hpp"
#include <iostream>

/*
    Use this main file as a demo
*/

using namespace GameObjects;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); //Randomization setup

    /*Creating scenes and showing what they are capable of*/
    static GameScene scene;
    static GameScene scene2;
    SceneControl::switchScene(scene);
    std::function<void()> beforeDrawFunction1 = []() {
        if ((rand() % 1000) == 0)
            std::cout << "1/1000 chance on scene 1!" << '\n';
        };
    std::function<void()> afterDrawFunction1 = []() {
        if ((rand() % 500) == 0)
            std::cout << "1/500 chance on scene 2!" << '\n';
        };
    scene.addBeforeDrawFunction(beforeDrawFunction1);
    scene2.addAfterDrawFunction(afterDrawFunction1);
    scene.keyPressFunctions[StateControl::scancodeToInt(sf::Keyboard::Scancode::E)] = []() {
        SceneControl::switchScene(scene2);
        };
    scene2.keyReleaseFunctions[StateControl::scancodeToInt(sf::Keyboard::Scancode::E)] = []() {
        if (scene2.hasProperty("ReleaseCancel")) scene2.deleteProperty("ReleaseCancel");
        else SceneControl::switchScene(scene);
        };
    scene2.switchedTo = [](GameScene& sceneBefore) { //There is also a switchedFrom method
        scene2.setProperty<void*>("ReleaseCancel", nullptr); //This line can be commented out safely to produce a different result
        scene2.backgroundColour = { static_cast<uint8_t>(rand() % 128), static_cast<uint8_t>(rand() % 128), static_cast<uint8_t>(rand() % 128) };
        return true;
        };

    /*Creating a text game object*/
    static sf::Font font("C:\\Windows\\Fonts\\BKANT.TTF");
    static std::shared_ptr<TextButton> button = GameButton::create<TextButton>(sf::Text(font), 42); 
    //When creating these shared pointers via the factory method, it's fine to use auto. This is merely for demonstration purposes.

    /*Defining how a button reacts on click and on hover*/
    button->onClick = [](sf::Mouse::Button mouseButton) { //There is also a onClickRelease method
        if (mouseButton != sf::Mouse::Button::Left) return;
        static int wow = 0;
        wow++;
        std::cout << std::to_string(wow) << " OMG IT WAS CLICKED\n";
        button->changeText("WOW\n" + std::to_string(wow));
    };
    button->onMouseMovement = [](sf::Vector2f mousePosition, sf::Vector2i mouseDelta) {
        if (button->isMouseHovering())
            button->setFillColor(sf::Color::Green);
        else 
            button->setFillColor(sf::Color::Yellow);
    };
    /*Then setting attributes*/
    button->changeText("WOW");
    button->setPosition({0, 0});
    button->setSize({200, 200});
    button->setFillColor(sf::Color::Yellow);
    button->text.setFillColor(sf::Color::Black);

    /*Creating a rectangle and setting its attributes*/
    static std::shared_ptr<GameRectangle> rect = GameShape::create<GameRectangle>(1); //Unsigned integer is zIndex.
    rect->setPosition({400, 200});
    rect->setSize({200, 200});

    /*Creating a circle and setting its attributes*/
    static std::shared_ptr<GameCircle> circle = GameShape::create<GameCircle>();
    circle->setPosition(sf::Vector2f(400, 200));
    circle->setRadius(100);
    circle->setFillColor(sf::Color(153, 153, 153));
    circle->setOutlineColor(sf::Color::Black);
    circle->setOutlineThickness(2);

    /*Creating a polygon and setting its points*/
    std::shared_ptr<GamePolygon> polygon = GameShape::create<GamePolygon>(1);
    polygon->setPointCount(4);
    polygon->setPoint(0, { 500, 500 });
    polygon->setPoint(1, { 600, 400 });
    polygon->setPoint(2, { 700, 500 });
    polygon->setPoint(3, { 600, 300 });
    /*Then setting its attributes*/
    polygon->setFillColor(sf::Color::Green);
    polygon->setOutlineColor(sf::Color::White);
    polygon->setOutlineThickness(5);

    /*Lastly, lets create an image button!*/
    sf::Texture texture("assets\\Green Circle of Basic.png", false, sf::IntRect({0,0}, {250,250}));
    std::shared_ptr<ImageButton> imageButton = GameButton::create<ImageButton>(texture, 1);
    imageButton->setPosition({ 1000, 500 });
    imageButton->onMouseMovement = [&imageButton](sf::Vector2f mousePosition, sf::Vector2i mouseDelta) {
        if (imageButton->isMouseHovering())
            imageButton->setTextureRect({ { 0, 125 }, { 250, 125 } });
        else
            imageButton->setTextureRect({ { 0, 0 }, { 250, 125 } });
        };
    //And it shall not do anything on click :)


    /*Anything between this and the below comment can be commented out safely*/

    scene.add(button).add(rect).add(circle).add(polygon);
    scene2.add(button).add(imageButton);
    //scene.remove(circle); 

    /*Anything between this and the above comment can be commented out safely*/


    WindowControl::beginWindowLoop("Demo", sf::State::Windowed, 30);
}
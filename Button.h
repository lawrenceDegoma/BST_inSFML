//
// Created by Lawrence Degoma on 3/28/24.
//

#ifndef BINARYSEARCHTREESFML_BUTTON_H
#define BINARYSEARCHTREESFML_BUTTON_H
#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;

public:
    Button(float x, float y, float width, float height, sf::Font& font, std::string textString);

    bool isClicked(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
};


#endif //BINARYSEARCHTREESFML_BUTTON_H

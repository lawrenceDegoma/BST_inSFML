//
// Created by Lawrence Degoma on 3/28/24.
//

#include "Button.h"
#include <iostream>

Button::Button(float x, float y, float width, float height, sf::Font& font, std::string textString) {
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color(255, 240, 200));

    text.setFont(font);
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return;
    }
    text.setString(textString);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 10, y + 10);
}

bool Button::isClicked(sf::RenderWindow& window) {
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
    return shape.getGlobalBounds().contains(mousePos);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

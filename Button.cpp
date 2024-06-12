//
// Created by Lawrence Degoma on 5/21/24.
//

#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font &font, std::string text) {
    button.setPosition(sf::Vector2f(x, y));
    button.setSize(sf::Vector2f(width, height));
    button.setFillColor(sf::Color::White);

    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(sf::Color::Black);

    centerText();  // Center the text within the button
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(button);
    window.draw(buttonText);
}

bool Button::isClicked(sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f translatedMousePos = window.mapPixelToCoords(mousePos);

        // Get the global bounds of the button
        sf::FloatRect globalBounds = button.getGlobalBounds();

        if (globalBounds.contains(translatedMousePos)) {
            return true;
        }
    }
    return false;
}

void Button::move(float offsetX, float offsetY) {
    button.move(offsetX, offsetY);
    buttonText.move(offsetX, offsetY);
}

void Button::centerText() {
    sf::FloatRect textRect = buttonText.getLocalBounds();
    sf::FloatRect buttonRect = button.getGlobalBounds();

    // Adjust text origin to its center
    buttonText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    // Set text position to the center of the button
    buttonText.setPosition(buttonRect.left + buttonRect.width / 2.0f, buttonRect.top + buttonRect.height / 2.0f);
}
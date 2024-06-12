//
// Created by Lawrence Degoma on 6/11/24.
//

#include "Helper.h"

template<typename T>
void Helper::centerText(const T &obj, sf::Text &text) {
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width / 2.0f, textRect.height / 2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width / 2, tRect.top + tRect.height / 2});
}

template void Helper::centerText<sf::RectangleShape>(const sf::RectangleShape &obj, sf::Text &text);
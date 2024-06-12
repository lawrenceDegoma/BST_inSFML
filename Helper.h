//
// Created by Lawrence Degoma on 6/11/24.
//

#ifndef BINARYSEARCHTREESFML_HELPER_H
#define BINARYSEARCHTREESFML_HELPER_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Helper {
public:
    template<typename T>
    static void centerText(const T &obj, sf::Text &text);
};

#endif //BINARYSEARCHTREESFML_HELPER_H

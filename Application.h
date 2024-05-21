//
// Created by Lawrence Degoma on 5/21/24.
//

#ifndef BINARYSEARCHTREESFML_APPLICATION_H
#define BINARYSEARCHTREESFML_APPLICATION_H

#include <SFML/Graphics.hpp>
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "Button.h"
#include "TreeType.h"
#include <iostream>
#include <ctime>

class Application {
public:
    Application();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handleButtonClicks();
    void traverseTree(BinarySearchTree& tree, std::vector<int>& sequence, TraversalType type);

    sf::RenderWindow window;
    sf::Font font;
    Button inorderButton;
    Button preorderButton;
    Button postorderButton;
    Button pushButton;
    Button resetButton;
    Button toggleButton;

    TreeType treeType;
    BinarySearchTree tree;
    AVLTree avlTree;

    TraversalType currentTraversal;
    std::vector<int> currentSequence;
};

#endif //BINARYSEARCHTREESFML_APPLICATION_H

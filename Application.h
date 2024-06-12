//
// Created by Lawrence Degoma on 5/21/24.
//

#ifndef BINARYSEARCHTREESFML_APPLICATION_H
#define BINARYSEARCHTREESFML_APPLICATION_H

#include <SFML/Graphics.hpp>
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "BTree.h"
#include "Button.h"
#include "TreeType.h"
#include <iostream>
#include <ctime>

class Application {
public:
    Application();
    void run();

private:
    sf::RenderWindow window;
    sf::Font font;
    Button inorderButton;
    Button preorderButton;
    Button postorderButton;
    Button pushButton;
    Button resetButton;
    Button toggleButton;
    BinarySearchTree tree;
    AVLTree avlTree;
    BTree bTree; // Add BTree member variable
    enum class TreeType { BST, AVL, BTree }; // Update TreeType enum
    TreeType treeType;
    enum class TraversalType { None, Inorder, Preorder, Postorder };
    TraversalType currentTraversal;
    std::vector<int> currentSequence;
    bool isDragging;
    sf::Vector2f lastMousePos;

    sf::Text treeTypeText;

    void processEvents();
    void update();
    void render();
    void handleButtonClicks();
    void traverseTree(BinarySearchTree& tree, std::vector<int>& sequence, TraversalType type);
    void traverseTree(AVLTree& tree, std::vector<int>& sequence, TraversalType type); // Add AVL overload
    void traverseTree(BTree& tree, std::vector<int>& sequence, TraversalType type); // Add BTree overload
    void updateTreeTypeText();
};

#endif //BINARYSEARCHTREESFML_APPLICATION_H

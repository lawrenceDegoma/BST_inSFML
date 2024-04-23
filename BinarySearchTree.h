//
// Created by Lawrence Degoma on 3/27/24.
//

#ifndef BINARYSEARCHTREESFML_BINARYSEARCHTREE_H
#define BINARYSEARCHTREESFML_BINARYSEARCHTREE_H


#include <SFML/Graphics.hpp>
#include <iostream>
//#include "Button.h"
#include "Node.h"

enum class TraversalType{
    None,
    Inorder,
    Preorder,
    Postorder
};

class BinarySearchTree {
private:
    Node* root;
    void inorderTraversal(Node* node, std::vector<int>& sequence);
    void preorderTraversal(Node* node, std::vector<int>& sequence);
    void postorderTraversal(Node* node, std::vector<int>& sequence);
    Node* insertRecursive(Node* node, int value);

public:
    BinarySearchTree();

    void insert(int value);


    void draw(sf::RenderWindow& window);
    void drawRecursive(sf::RenderWindow& window, Node* node, float x, float y, float offsetX, float offsetY);

    void inorderTraversal(std::vector<int>& sequence);
    void preorderTraversal(std::vector<int>& sequence);
    void postorderTraversal(std::vector<int>& sequence);
};


#endif //BINARYSEARCHTREESFML_BINARYSEARCHTREE_H

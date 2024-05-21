//
// Created by Lawrence Degoma on 5/21/24.
//

#ifndef BINARYSEARCHTREESFML_BINARYSEARCHTREE_H
#define BINARYSEARCHTREESFML_BINARYSEARCHTREE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "TraversalType.h"
#include "Node.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include "TraversalType.h"
#include "Node.h"

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int value);
    void clear();
    void inorderTraversal(std::vector<int>& sequence);
    void preorderTraversal(std::vector<int>& sequence);
    void postorderTraversal(std::vector<int>& sequence);
    void draw(sf::RenderWindow& window);
    void setFont(const sf::Font& font);

protected:
    Node* root;
    const sf::Font* font;
    void insert(Node*& node, int value);
    void clear(Node* node);
    void inorderTraversal(Node* node, std::vector<int>& sequence);
    void preorderTraversal(Node* node, std::vector<int>& sequence);
    void postorderTraversal(Node* node, std::vector<int>& sequence);
    void draw(Node* node, sf::RenderWindow& window, int x, int y, int xOffset);
};


#endif //BINARYSEARCHTREESFML_BINARYSEARCHTREE_H

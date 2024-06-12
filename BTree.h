//
// Created by Lawrence Degoma on 6/11/24.
//

#ifndef BINARYSEARCHTREESFML_BTREE_H
#define BINARYSEARCHTREESFML_BTREE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class BTree {
private:
    struct Node {
        std::vector<int> keys;
        std::vector<Node *> children;
        bool isLeaf;
        int n;

        Node(int degree, bool isLeaf);

        void insertNonFull(int key, int degree);
        void splitChild(int i, Node *y, int degree);
        void draw(sf::RenderWindow &window, sf::Font &font, float x, float y, float level);
    };

    Node *root;
    int degree;
    sf::Font font;

    void drawNode(Node *node, sf::RenderWindow &window, float x, float y, float level);
    void clearNode(Node *node);

    void inorderTraversal(Node* node, std::vector<int>& sequence);
    void preorderTraversal(Node* node, std::vector<int>& sequence);
    void postorderTraversal(Node* node, std::vector<int>& sequence);

public:
    BTree(int degree = 3);
    void setFont(const sf::Font &font);
    void insert(int key);
    void clear();
    void draw(sf::RenderWindow &window);

    void inorderTraversal(std::vector<int>& sequence);
    void preorderTraversal(std::vector<int>& sequence);
    void postorderTraversal(std::vector<int>& sequence);
};


#endif //BINARYSEARCHTREESFML_BTREE_H

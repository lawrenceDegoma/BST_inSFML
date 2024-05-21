//
// Created by Lawrence Degoma on 5/21/24.
//

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr), font(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    clear();
}

void BinarySearchTree::insert(int value) {
    insert(root, value);
}

void BinarySearchTree::clear() {
    clear(root);
    root = nullptr;
}

void BinarySearchTree::inorderTraversal(std::vector<int>& sequence) {
    inorderTraversal(root, sequence);
}

void BinarySearchTree::preorderTraversal(std::vector<int>& sequence) {
    preorderTraversal(root, sequence);
}

void BinarySearchTree::postorderTraversal(std::vector<int>& sequence) {
    postorderTraversal(root, sequence);
}

void BinarySearchTree::draw(sf::RenderWindow& window) {
    draw(root, window, 450, 50, 300);
}

void BinarySearchTree::setFont(const sf::Font& font) {
    this->font = &font;
}

void BinarySearchTree::insert(Node*& node, int value) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else {
        insert(node->right, value);
    }
}

void BinarySearchTree::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void BinarySearchTree::inorderTraversal(Node* node, std::vector<int>& sequence) {
    if (node != nullptr) {
        inorderTraversal(node->left, sequence);
        sequence.push_back(node->data);
        inorderTraversal(node->right, sequence);
    }
}

void BinarySearchTree::preorderTraversal(Node* node, std::vector<int>& sequence) {
    if (node != nullptr) {
        sequence.push_back(node->data);
        preorderTraversal(node->left, sequence);
        preorderTraversal(node->right, sequence);
    }
}

void BinarySearchTree::postorderTraversal(Node* node, std::vector<int>& sequence) {
    if (node != nullptr) {
        postorderTraversal(node->left, sequence);
        postorderTraversal(node->right, sequence);
        sequence.push_back(node->data);
    }
}

void BinarySearchTree::draw(Node* node, sf::RenderWindow& window, int x, int y, int xOffset) {
    if (node != nullptr) {
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::White);
        circle.setPosition(x, y);
        window.draw(circle);

        if (font) {
            sf::Text text;
            text.setFont(*font);
            text.setString(std::to_string(node->data));
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Black);
            text.setPosition(x + 10, y + 10);
            window.draw(text);
        }

        int newOffset = xOffset / 2;

        if (node->left != nullptr) {
            sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x + 20, y + 20)),
                    sf::Vertex(sf::Vector2f(x - newOffset + 20, y + 70))
            };
            window.draw(line, 2, sf::Lines);
            draw(node->left, window, x - newOffset, y + 70, newOffset);
        }

        if (node->right != nullptr) {
            sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x + 20, y + 20)),
                    sf::Vertex(sf::Vector2f(x + newOffset + 20, y + 70))
            };
            window.draw(line, 2, sf::Lines);
            draw(node->right, window, x + newOffset, y + 70, newOffset);
        }
    }
}
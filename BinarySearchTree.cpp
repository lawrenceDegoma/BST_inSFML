#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

void BinarySearchTree::insert(int value) {
    root = insertRecursive(root, value);
}

Node* BinarySearchTree::insertRecursive(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->value) {
        node->left = insertRecursive(node->left, value);
    } else if (value > node->value) {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

void BinarySearchTree::draw(sf::RenderWindow& window) {
    drawRecursive(window, root, 400, 50, 300, 100);
}

void BinarySearchTree::drawRecursive(sf::RenderWindow& window, Node* node, float x, float y, float offsetX, float offsetY) {
    if (node != nullptr) {
        sf::CircleShape circle(25);
        circle.setPosition(x, y);
        circle.setFillColor(sf::Color::White);
        circle.setOutlineThickness(2);
        circle.setOutlineColor(sf::Color::Black);

        window.draw(circle);

        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Failed to load font" << std::endl;
            return;
        }

        sf::Text text(std::to_string(node->value), font, 20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + 10, y + 10);

        window.draw(text);

        float nextOffsetX = offsetX / 2;
        drawRecursive(window, node->left, x - nextOffsetX, y + offsetY, nextOffsetX, offsetY);
        drawRecursive(window, node->right, x + nextOffsetX, y + offsetY, nextOffsetX, offsetY);
    }
}

void BinarySearchTree::inorderTraversal(std::vector<int>& sequence) {
    inorderTraversal(root, sequence);
}

void BinarySearchTree::inorderTraversal(Node* node, std::vector<int>& sequence) {
    if (node == nullptr) return;
    inorderTraversal(node->left, sequence);
    sequence.push_back(node->value);
    inorderTraversal(node->right, sequence);
}

void BinarySearchTree::preorderTraversal(std::vector<int>& sequence) {
    preorderTraversal(root, sequence);
}

void BinarySearchTree::preorderTraversal(Node* node, std::vector<int>& sequence) {
    if (node == nullptr) return;
    sequence.push_back(node->value);
    preorderTraversal(node->left, sequence);
    preorderTraversal(node->right, sequence);
}

void BinarySearchTree::postorderTraversal(std::vector<int>& sequence) {
    postorderTraversal(root, sequence);
}

void BinarySearchTree::postorderTraversal(Node* node, std::vector<int>& sequence) {
    if (node == nullptr) return;
    postorderTraversal(node->left, sequence);
    postorderTraversal(node->right, sequence);
    sequence.push_back(node->value);
}
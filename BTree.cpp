//
// Created by Lawrence Degoma on 6/11/24.
//

#include "BTree.h"

BTree::BTree(int degree) : root(nullptr), degree(degree) {}

void BTree::setFont(const sf::Font &font) {
    this->font = font;
}

void BTree::insert(int key) {
    std::cout << "Inserting key: " << key << std::endl;

    if (!root) {
        std::cout << "Root is null. Creating new root node." << std::endl;
        root = new Node(degree, true);
        root->keys.push_back(key);
        root->n = 1;
    } else {
        std::cout << "Root exists. Inserting into existing tree." << std::endl;
        if (root->n == 2 * degree - 1) {
            std::cout << "Root is full. Splitting root." << std::endl;
            Node *s = new Node(degree, false);
            s->children.push_back(root);
            s->splitChild(0, root, degree);

            int i = 0;
            if (s->keys[0] < key) i++;
            s->children[i]->insertNonFull(key, degree);

            root = s;
        } else {
            std::cout << "Root is not full. Inserting into root." << std::endl;
            root->insertNonFull(key, degree);
        }
    }
}

void BTree::clear() {
    if (root) {
        clearNode(root);
        root = nullptr;
    }
}

void BTree::clearNode(Node *node) {
    if (!node->isLeaf) {
        for (auto child : node->children) {
            clearNode(child);
        }
    }
    delete node;
}

void BTree::draw(sf::RenderWindow &window) {
    if (root) {
        drawNode(root, window, window.getSize().x / 2, 50, 1);
    }
}

void BTree::drawNode(Node *node, sf::RenderWindow &window, float x, float y, float level) {
    float horizontalSpacing = 100 / level;
    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::White);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(2);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);

    for (int i = 0; i < node->n; i++) {
        float nodeX = x + (i - node->n / 2.0f) * horizontalSpacing;
        circle.setPosition(nodeX - circle.getRadius(), y - circle.getRadius());
        window.draw(circle);

        text.setString(std::to_string(node->keys[i]));
        text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
        text.setPosition(nodeX, y);
        window.draw(text);
    }

    if (!node->isLeaf) {
        for (int i = 0; i <= node->n; i++) {
            float childX = x + (i - node->n / 2.0f) * horizontalSpacing;
            drawNode(node->children[i], window, childX, y + 100, level + 1);
        }
    }
}

BTree::Node::Node(int degree, bool isLeaf) : isLeaf(isLeaf), n(0) {
    keys.resize(2 * degree - 1);
    children.resize(2 * degree);
}

void BTree::Node::splitChild(int i, Node* y, int degree) {
    Node* z = new Node(degree, y->isLeaf);
    z->n = degree - 1;

    for (int j = 0; j < degree; j++) { // Update loop to copy degree keys
        z->keys[j] = y->keys[j + degree];
    }

    if (!y->isLeaf) {
        for (int j = 0; j < degree; j++) { // Update loop to copy degree children
            z->children[j] = y->children[j + degree];
        }
    }

    y->n = degree - 1; // Update n for the original node
    z->n = degree - 1; // Update n for the newly created node

    children.insert(children.begin() + i + 1, z);
    while (children.size() < 2 * degree) {
        children.push_back(nullptr); // Ensure capacity for children
    }
    keys.insert(keys.begin() + i, y->keys[degree - 1]);
    n++;
}

void BTree::Node::insertNonFull(int key, int degree) {
    int i = n - 1;
    if (isLeaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        n++;
    } else {
        while (i >= 0 && keys[i] > key) {
            i--;
        }
        if (children[i + 1]->n == 2 * degree - 1) {
            splitChild(i + 1, children[i + 1], degree);
            if (keys[i + 1] < key) {
                i++;
            }
        }
        children[i + 1]->insertNonFull(key, degree);
    }
}

void BTree::inorderTraversal(std::vector<int>& sequence) {
    inorderTraversal(root, sequence);
}

void BTree::inorderTraversal(Node* node, std::vector<int>& sequence) {
    if (node == nullptr) return;

    int i;
    for (i = 0; i < node->n; ++i) {
        inorderTraversal(node->children[i], sequence);
        if (i < node->n - 1)
            sequence.push_back(node->keys[i]);
    }
    inorderTraversal(node->children[i], sequence);
}

void BTree::preorderTraversal(std::vector<int>& sequence) {
    preorderTraversal(root, sequence);
}

void BTree::preorderTraversal(Node* node, std::vector<int>& sequence) {
    if (node == nullptr) return;

    for (int i = 0; i < node->n; ++i) {
        sequence.push_back(node->keys[i]);
        preorderTraversal(node->children[i], sequence);
    }
    preorderTraversal(node->children[node->n], sequence);
}

void BTree::postorderTraversal(std::vector<int>& sequence) {
    postorderTraversal(root, sequence);
}

void BTree::postorderTraversal(Node* node, std::vector<int>& sequence) {
    if (node == nullptr) return;

    for (int i = 0; i < node->n; ++i) {
        postorderTraversal(node->children[i], sequence);
    }
    postorderTraversal(node->children[node->n], sequence);
    for (int i = 0; i < node->n; ++i) {
        sequence.push_back(node->keys[i]);
    }
}
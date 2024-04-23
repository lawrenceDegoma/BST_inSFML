#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "BinarySearchTree.h"
#include "Button.h"

void traverseTree(BinarySearchTree&, std::vector<int>&, TraversalType);

int main() {
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(900, 800), "Binary Search Tree");
    window.setFramerateLimit(60);
    window.clear(sf::Color(173, 216, 230)); // Set background color

    BinarySearchTree tree;

    sf::Font font;
    // load font and throw and error if it fails
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return 1;
    }

    // create buttons for traversals and insertion
    Button inorderButton(150, 700, 100, 50, font, "Inorder");
    Button preorderButton(300, 700, 100, 50, font, "Preorder");
    Button postorderButton(450, 700, 100, 50, font, "Postorder");
    Button pushButton(600, 700, 100, 50, font, "Push");

    // Initialize traveresal type
    TraversalType currentTraversal = TraversalType::None;
    // Store current traversal sequence in a vector
    std::vector<int> currentSequence;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (pushButton.isClicked(window)) {
                    int value = rand() % 100 + 1; // Generate random numb in range 1 to 100
                    tree.insert(value);
                }
                if (inorderButton.isClicked(window)) {
                    currentTraversal = TraversalType::Inorder;
                    traverseTree(tree, currentSequence, currentTraversal);
                }
                if (preorderButton.isClicked(window)) {
                    currentTraversal = TraversalType::Preorder;
                    traverseTree(tree, currentSequence, currentTraversal);
                }
                if (postorderButton.isClicked(window)) {
                    currentTraversal = TraversalType::Postorder;
                    traverseTree(tree, currentSequence, currentTraversal);
                }
            }
        }

        window.clear(sf::Color(173, 216, 230)); // Clear with background color
        // draw tree and buttons
        tree.draw(window);
        inorderButton.draw(window);
        preorderButton.draw(window);
        postorderButton.draw(window);
        pushButton.draw(window);

        // determine sequence type
        sf::Text sequenceText;
        sequenceText.setFont(font);
        sequenceText.setCharacterSize(20);
        sequenceText.setFillColor(sf::Color::Black);
        sequenceText.setPosition(50, 600);
        std::string sequenceStr;
        if (currentTraversal != TraversalType::None) {
            switch (currentTraversal) {
                case TraversalType::Inorder:
                    sequenceStr = "Inorder sequence: ";
                    break;
                case TraversalType::Preorder:
                    sequenceStr = "Preorder sequence: ";
                    break;
                case TraversalType::Postorder:
                    sequenceStr = "Postorder sequence: ";
                    break;
                default:
                    break;
            }
            for (int value : currentSequence) {
                sequenceStr += std::to_string(value) + " ";
            }
            sequenceText.setString(sequenceStr);
            window.draw(sequenceText);
        }

        window.display();
    }

    return 0;
}

void traverseTree(BinarySearchTree& tree, std::vector<int>& sequence, TraversalType type){
    sequence.clear();
    // sequence.clear() removes all elements from a container. Resets display when a new button is pressed
    switch (type){
        case TraversalType::Inorder:
            tree.inorderTraversal(sequence);
            break;
        case TraversalType::Preorder:
            tree.preorderTraversal(sequence);
            break;
        case TraversalType::Postorder:
            tree.postorderTraversal(sequence);
            break;
    }
}
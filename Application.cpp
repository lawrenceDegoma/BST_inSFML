//
// Created by Lawrence Degoma on 5/21/24.
//

#include "Application.h"

Application::Application()
        : window(sf::VideoMode(900, 800), "Tree Visualizer"),
          inorderButton(150, 700, 100, 50, font, "Inorder"),
          preorderButton(300, 700, 100, 50, font, "Preorder"),
          postorderButton(450, 700, 100, 50, font, "Postorder"),
          pushButton(600, 700, 100, 50, font, "Push"),
          resetButton(750, 700, 100, 50, font, "Reset"),
          toggleButton(750, 600, 100, 50, font, "Toggle"),
          treeType(TreeType::BST),
          currentTraversal(TraversalType::None) {

    window.setFramerateLimit(60);

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        exit(1);
    }

    tree.setFont(font);
    avlTree.setFont(font);
}

void Application::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            handleButtonClicks();
        }
    }
}

void Application::update() {
    // Update application state if needed
}

void Application::render() {
    window.clear(sf::Color(173, 216, 230)); // Clear with background color

    if (treeType == TreeType::BST) {
        tree.draw(window);
    } else {
        avlTree.draw(window);
    }

    inorderButton.draw(window);
    preorderButton.draw(window);
    postorderButton.draw(window);
    pushButton.draw(window);
    resetButton.draw(window);
    toggleButton.draw(window);

    if (currentTraversal != TraversalType::None) {
        sf::Text sequenceText;
        sequenceText.setFont(font);
        sequenceText.setCharacterSize(20);
        sequenceText.setFillColor(sf::Color::Black);
        sequenceText.setPosition(50, 600);
        std::string sequenceStr;
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

void Application::handleButtonClicks() {
    if (pushButton.isClicked(window)) {
        int value = rand() % 100 + 1;
        if (treeType == TreeType::BST) {
            tree.insert(value);
        } else {
            avlTree.insert(value);
        }
    }
    if (resetButton.isClicked(window)) {
        if (treeType == TreeType::BST) {
            tree.clear();
        } else {
            avlTree.clear();
        }
    }
    if (toggleButton.isClicked(window)) {
        treeType = (treeType == TreeType::BST) ? TreeType::AVL : TreeType::BST;
    }
    if (inorderButton.isClicked(window)) {
        currentTraversal = TraversalType::Inorder;
        if (treeType == TreeType::BST) {
            traverseTree(tree, currentSequence, currentTraversal);
        } else {
            traverseTree(avlTree, currentSequence, currentTraversal);
        }
    }
    if (preorderButton.isClicked(window)) {
        currentTraversal = TraversalType::Preorder;
        if (treeType == TreeType::BST) {
            traverseTree(tree, currentSequence, currentTraversal);
        } else {
            traverseTree(avlTree, currentSequence, currentTraversal);
        }
    }
    if (postorderButton.isClicked(window)) {
        currentTraversal = TraversalType::Postorder;
        if (treeType == TreeType::BST) {
            traverseTree(tree, currentSequence, currentTraversal);
        } else {
            traverseTree(avlTree, currentSequence, currentTraversal);
        }
    }
}

void Application::traverseTree(BinarySearchTree& tree, std::vector<int>& sequence, TraversalType type) {
    sequence.clear();
    switch (type) {
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
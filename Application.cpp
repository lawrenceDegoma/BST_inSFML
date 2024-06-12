//
// Created by Lawrence Degoma on 5/21/24.
//

#include "Application.h"

Application::Application()
        : window(sf::VideoMode(1280, 720), "Tree Visualizer"),
          inorderButton(150, 600, 100, 50, font, "Inorder"),
          preorderButton(300, 600, 100, 50, font, "Preorder"),
          postorderButton(450, 600, 100, 50, font, "Postorder"),
          pushButton(600, 600, 100, 50, font, "Push"),
          resetButton(750, 600, 100, 50, font, "Reset"),
          toggleButton(750, 500, 100, 50, font, "Toggle"),
          treeType(TreeType::BST),
          currentTraversal(TraversalType::None),
          isDragging(false),
          bTree() { // Explicitly initialize bTree
    window.setFramerateLimit(60);

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        exit(1);
    }

    tree.setFont(font);
    avlTree.setFont(font);
    bTree.setFont(font); // Set font for BTree

    // Initialize the tree type text
    treeTypeText.setFont(font);
    treeTypeText.setCharacterSize(20);
    treeTypeText.setFillColor(sf::Color::Black);
    updateTreeTypeText();
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
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    isDragging = true;
                    lastMousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                }
                handleButtonClicks();
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    isDragging = false;
                }
                break;
            case sf::Event::MouseMoved:
                if (isDragging) {
                    sf::Vector2f newMousePos = window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
                    sf::Vector2f delta = lastMousePos - newMousePos;
                    sf::View view = window.getView();
                    view.setCenter(view.getCenter() - delta);
                    window.setView(view);
                    lastMousePos = newMousePos;
                }
                break;
            default:
                break;
        }
    }
}

void Application::update() {
    // Update application state if needed
}

void Application::render() {
    window.clear(sf::Color(173, 216, 230)); // Clear with background color

    switch (treeType) {
        case TreeType::BST:
            tree.draw(window);
            break;
        case TreeType::AVL:
            avlTree.draw(window);
            break;
        case TreeType::BTree:
            bTree.draw(window);
            break;
    }

    // Update button positions regardless of dragging
    sf::Vector2f delta = sf::Vector2f(0.f, 0.f);
    if (isDragging) {
        // Adjust button positions based on the mouse movement
        delta = lastMousePos - window.mapPixelToCoords(sf::Mouse::getPosition(window));
        lastMousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    }

    inorderButton.move(-delta.x, -delta.y);
    preorderButton.move(-delta.x, -delta.y);
    postorderButton.move(-delta.x, -delta.y);
    pushButton.move(-delta.x, -delta.y);
    resetButton.move(-delta.x, -delta.y);
    toggleButton.move(-delta.x, -delta.y);
    treeTypeText.move(-delta.x, -delta.y);

    // Draw buttons
    inorderButton.draw(window);
    preorderButton.draw(window);
    postorderButton.draw(window);
    pushButton.draw(window);
    resetButton.draw(window);
    toggleButton.draw(window);

    // Draw tree type text
    window.draw(treeTypeText);

    // Draw traversal sequence text if applicable
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
        switch (treeType) {
            case TreeType::BST:
                tree.insert(value);
                break;
            case TreeType::AVL:
                avlTree.insert(value);
                break;
            case TreeType::BTree:
                bTree.insert(value);
                break;
        }
    }
    if (resetButton.isClicked(window)) {
        switch (treeType) {
            case TreeType::BST:
                tree.clear();
                break;
            case TreeType::AVL:
                avlTree.clear();
                break;
            case TreeType::BTree:
                bTree.clear();
                break;
        }
    }
    if (toggleButton.isClicked(window)) {
        switch (treeType) {
            case TreeType::BST:
                treeType = TreeType::AVL;
                break;
            case TreeType::AVL:
                treeType = TreeType::BTree;
                break;
            case TreeType::BTree:
                treeType = TreeType::BST;
                break;
        }
        updateTreeTypeText();
    }
    if (inorderButton.isClicked(window)) {
        currentTraversal = TraversalType::Inorder;
        switch (treeType) {
            case TreeType::BST:
                traverseTree(tree, currentSequence, currentTraversal);
                break;
            case TreeType::AVL:
                traverseTree(avlTree, currentSequence, currentTraversal);
                break;
            case TreeType::BTree:
                traverseTree(bTree, currentSequence, currentTraversal);
                break;
        }
    }
    if (preorderButton.isClicked(window)) {
        currentTraversal = TraversalType::Preorder;
        switch (treeType) {
            case TreeType::BST:
                traverseTree(tree, currentSequence, currentTraversal);
                break;
            case TreeType::AVL:
                traverseTree(avlTree, currentSequence, currentTraversal);
                break;
            case TreeType::BTree:
                traverseTree(bTree, currentSequence, currentTraversal);
                break;
        }
    }
    if (postorderButton.isClicked(window)) {
        currentTraversal = TraversalType::Postorder;
        switch (treeType) {
            case TreeType::BST:
                traverseTree(tree, currentSequence, currentTraversal);
                break;
            case TreeType::AVL:
                traverseTree(avlTree, currentSequence, currentTraversal);
                break;
            case TreeType::BTree:
                traverseTree(bTree, currentSequence, currentTraversal);
                break;
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
        default:
            break;
    }
}

void Application::traverseTree(AVLTree& tree, std::vector<int>& sequence, TraversalType type) {
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
        default:
            break;
    }
}

void Application::traverseTree(BTree& tree, std::vector<int>& sequence, TraversalType type) {
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
        default:
            break;
    }
}

void Application::updateTreeTypeText() {
    switch (treeType) {
        case TreeType::BST:
            treeTypeText.setString("Current Tree: BST");
            break;
        case TreeType::AVL:
            treeTypeText.setString("Current Tree: AVL");
            break;
        case TreeType::BTree:
            treeTypeText.setString("Current Tree: BTree");
            break;
    }
    // Set the initial position of the text
    treeTypeText.setPosition(50, 50);  // Adjust the position as needed
}
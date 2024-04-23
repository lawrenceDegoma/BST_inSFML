//
// Created by Lawrence Degoma on 3/28/24.
//

#ifndef BINARYSEARCHTREESFML_NODE_H
#define BINARYSEARCHTREESFML_NODE_H


struct Node {
public:
    int value;
    Node* left;
    Node* right;
    explicit Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

#endif //BINARYSEARCHTREESFML_NODE_H

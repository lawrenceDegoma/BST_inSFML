//
// Created by Lawrence Degoma on 5/21/24.
//

#ifndef BINARYSEARCHTREESFML_AVLTREE_H
#define BINARYSEARCHTREESFML_AVLTREE_H

#include "BinarySearchTree.h"

class AVLTree : public BinarySearchTree {
public:
    void insert(int value);
private:
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* balance(Node* node);
    int getHeight(Node* node);
    int getBalanceFactor(Node* node);
    Node* insert(Node* node, int value);
};

#endif //BINARYSEARCHTREESFML_AVLTREE_H

//
// Created by Lawrence Degoma on 5/21/24.
//

#ifndef BINARYSEARCHTREESFML_NODE_H
#define BINARYSEARCHTREESFML_NODE_H


class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value);
};


#endif //BINARYSEARCHTREESFML_NODE_H

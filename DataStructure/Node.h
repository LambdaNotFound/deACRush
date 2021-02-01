#ifndef ACRUSH_NODE_H
#define ACRUSH_NODE_H

#include "StandardLibrary"

// node for linked list or doubly linked list
struct Node {
    int val;
    Node* left;
    Node* right;

    Node() : prev(nullptr), next(nullptr) {}

    Node(int value) : val(value), prev(nullptr), next(nullptr) {}
};

#endif //ACRUSH_NODE_H

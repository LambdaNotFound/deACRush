#ifndef ACRUSH_NODE_H
#define ACRUSH_NODE_H

#include "StandardLibrary"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

#endif //ACRUSH_NODE_H

#ifndef ACRUSH_NODE_H
#define ACRUSH_NODE_H

#include "StandardLibrary.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next; // tree node to linked list node

    vector<Node*> neighbors; // graph node

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
        neighbors = vector<Node*>();
    }

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {
        neighbors = vector<Node*>();
    }

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {
        neighbors = vector<Node*>();
    }

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {
            neighbors = vector<Node*>();
    }
};

#endif //ACRUSH_NODE_H

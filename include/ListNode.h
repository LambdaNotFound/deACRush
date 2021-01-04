#ifndef ACRUSH_LISTNODE_H
#define ACRUSH_LISTNODE_H

#include <memory>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode() : val(-1), next(nullptr) {
    }
};

template<typename T>
struct Node {
    T val;
    std::unique_ptr<Node> next;
    Node(T x) : val(x), next(nullptr) {
    }
};

#endif //ACRUSH_LISTNODE_H

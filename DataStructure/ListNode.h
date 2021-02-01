#ifndef ACRUSH_LINKEDLIST_H
#define ACRUSH_LINKEDLIST_H

#include "StandardLibrary"

// namespace alt { // alternative impl

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#endif //ACRUSH_LINKEDLIST_H

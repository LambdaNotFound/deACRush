#ifndef ACRUSH_LISTNODE_H
#define ACRUSH_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

#endif //ACRUSH_LISTNODE_H

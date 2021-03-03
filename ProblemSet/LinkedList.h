#ifndef ACRUSH_LINKEDLIST_H
#define ACRUSH_LINKEDLIST_H

#include "StandardLibrary.h"

using namespace std;

class Node;

class LinkedList {
/*
 *  138. Copy List with Random Pointer
 *
 * i. Space O(1): cur->next->random = cur->random->next
 */
public:
    Node* copyRandomList(Node* head);

};

#endif //ACRUSH_LINKEDLIST_H

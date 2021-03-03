#include "LinkedList.h"

#include "Node.h"

// 138. Copy List with Random Pointer
Node* LinkedList::copyRandomList(Node* head) {
    if (!head)
        return nullptr;
    Node *cur = head;
    while (cur) {
        Node *t = new Node(cur->val, nullptr, nullptr);
        t->next = cur->next;
        cur->next = t;
        cur = t->next;
    }
    cur = head;
    while (cur) {
        if (cur->random)
            cur->next->random = cur->random->next;
        cur = cur->next->next;
    }
    cur = head;
    Node *res = head->next;
    while (cur) {
        Node *t = cur->next;
        cur->next = t->next;
        if (t->next)
            t->next = t->next->next;
        cur = cur->next;
    }
    return res;
}

Node* copyRandomList(Node* head) {
    if (!head)
        return nullptr;

    unordered_map<Node*, Node*> copiedNode;
    Node *headCopy = new Node(head->val);
    copiedNode[head] = headCopy;
    for (Node* cur = head; cur->next; cur = cur->next) {
        if (!copiedNode.count(cur->next))
            copiedNode[cur->next] = new Node(cur->next->val);

        copiedNode[cur]->next = copiedNode[cur->next];
    }

    for (Node* cur = head; cur; cur = cur->next) {
        copiedNode[cur]->random = copiedNode[cur->random];
    }

    return headCopy;
}

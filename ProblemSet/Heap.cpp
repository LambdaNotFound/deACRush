#include "Heap.h"
#include "ListNode.h"

using namespace std;

// 23. Merge k Sorted Lists
ListNode* Heap::mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode*& a, ListNode*& b) {
                   return a->val > b->val;
               };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);

    for (auto node : lists)
        if (node)
            q.push(node);

    ListNode dummy(-1), *cur = &dummy;
    while (!q.empty()) {
        auto tmp = q.top(); q.pop();
        if (tmp->next)
            q.push(tmp->next);

        cur->next = tmp;
        cur = cur->next;
    }

    return dummy.next;
}

Heap::KthLargest::KthLargest(int k, vector<int>& nums) {
    capacity = k;
    for (int num : nums) {
        q.push(num);
        if (q.size() > capacity)
            q.pop();
    }
}

int Heap::KthLargest::add(int val) {
    q.push(val);
    if (q.size() > capacity)
        q.pop();
    return q.top();
}

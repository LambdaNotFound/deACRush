#include "Heap.h"
#include "ListNode.h"

using namespace std;

// 23. Merge k Sorted Lists
ListNode* Heap::mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode*& a, ListNode*& b) {
                   return a->val > b->val;
               };

    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > heap(cmp);

    for (auto node : lists)
        if (node)
            heap.push(node);

    ListNode dummy(-1), *cur = &dummy;
    while (!heap.empty()) {
        auto tmp = heap.top(); heap.pop();
        if (tmp->next)
            heap.push(tmp->next);

        cur->next = tmp;
        cur = cur->next;
    }

    return dummy.next;
}

// 347. Top K Frequent Elements
vector<int> Heap::topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> hashMap;
    priority_queue<pair<int, int> > heap;
    for (auto e: nums)
        ++hashMap[e];
    for (auto e: hashMap)
        heap.push(make_pair(e.second, e.first));
    for (int i = 0; i < k; ++i) {
        res.push_back(heap.top().second); heap.pop();
    }
    return res;
}

// 703. Kth Largest Element in a Stream
Heap::KthLargest::KthLargest(int k, vector<int>& nums) {
    capacity = k;
    for (int num : nums) {
        heap.push(num);
        if (heap.size() > capacity)
            heap.pop();
    }
}

int Heap::KthLargest::add(int val) {
    heap.push(val);
    if (heap.size() > capacity)
        heap.pop();
    return heap.top();
}

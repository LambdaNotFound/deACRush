#ifndef ACRUSH_HEAP_H
#define ACRUSH_HEAP_H

#include "StandardLibrary.h"

using namespace std;

struct ListNode;

/**
 * Priority Queue
 *
 * A priority queue can have any implementation, e.g. binary heap
 *
 * Min-Heap: Where the value of the root node is less than or equal to either of its children
 * Max-Heap: Where the value of the root node is greater than or equal to either of its children
 */

class Heap {
/*
 * 23. Merge k Sorted Lists
 *
 * i. DivideAndConquer
 * ii. Heap <= LIKE
 *
 * use a dummy header for linked lists
 */
public:
    ListNode* mergeKLists(vector<ListNode*>& lists);

/*
 * 347. Top K Frequent Elements
 *
 * i. HashMap + Heap
 *
 */
public:
    vector<int> topKFrequent(vector<int>& nums, int k);

/*
 * 703. Kth Largest Element in a Stream
 *
 * i. Min-Heap
 *
 */
public:
    class KthLargest {
    public:
        KthLargest(int k, vector<int>& nums);

        int add(int val);

    private:
        priority_queue<int, vector<int>, greater<int>> heap;

        int capacity;
    };

};

#endif //ACRUSH_HEAP_H

#include "gtest/gtest.h"

#include "../../ProblemSet/Heap.h"

using namespace std;

TEST(PriorityQueueComparator, Heap) {
    auto cmp = [](int a, int b) -> bool {
                   return a > b;
               };
    priority_queue<int, vector<int>, decltype(cmp) > q1(cmp);
    for (int i = 0; i < 10; ++i)
        q1.push(i);

    vector<int> expected = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(q1.top(), expected[i]);
        q1.pop();
    }

    priority_queue<int> q2; // Max-Heap is the default for priority queue
    for (int i = 0; i < 10; ++i)
        q2.push(i);
    q2.push(6);
    expected = { 9, 8, 7, 6, 6, 5, 4, 3, 2, 1, 0 };
    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(q2.top(), expected[i]);
        q2.pop();
    }
}

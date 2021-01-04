#include "gtest/gtest.h"

#include "../Algorithm/Sorting/InsertionSort.h"
#include "../Algorithm/Sorting/MergeSort.h"
#include "../Algorithm/Sorting/Rotate.h"

using namespace std;

TEST(upper_bound, MergeSort) {
    // template< class ForwardIt, class T >
    // ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value );
    // MUST BE USED ON FULLY SORTED RANGE: !(value < element)
    vector<int> input { 1, 1, 2, 3, 4, 5 };
    vector<int>::iterator upperBound = std::upper_bound(input.begin(), input.end(), 1); // [first, last)

    EXPECT_EQ(upperBound, input.begin() + 2);
    EXPECT_EQ(*upperBound, 2);

    upperBound = std::upper_bound(input.begin(), input.end(), 0);
    EXPECT_EQ(upperBound, input.begin());
    EXPECT_EQ(*upperBound, 1);

    upperBound = std::upper_bound(input.begin(), input.end(), 5);
    EXPECT_EQ(upperBound, input.end());

    upperBound = std::upper_bound(input.begin(), input.end(), 6);
    EXPECT_EQ(upperBound, input.end());

    int dist = std::distance(input.begin(), input.end());
    EXPECT_EQ(dist, input.size());

    vector<int>::iterator n_first = input.begin() + 2;
    vector<int>::iterator first = std::rotate(input.begin(), n_first, input.end());
    EXPECT_EQ(first, input.begin() + 4); // first + (last - n_first)

    vector<int> expected { 2, 3, 4, 5, 1, 1 };
    EXPECT_EQ(input, expected);
}

TEST(rotate, MergeSort) {
    vector<int> input { 0, 1, 2, 3, 4, 5 };
    rotate_debug<vector<int>::iterator>(input.begin(), input.begin() + 1, input.end());

    vector<int> expected { 1, 2, 3, 4, 5, 0 };
    EXPECT_EQ(input, expected);

    input = { 0, 1, 2, 3, 4, 5 };
    rotate_debug<vector<int>::iterator>(input.begin(), input.begin() + 4, input.end());
    expected = { 4, 5, 0, 1, 2, 3 };
    EXPECT_EQ(input, expected);
}

TEST(rotate, InsertionSort) {
    vector<int> input {1, 8, 3, 6, 5, 4, 7, 2, 9, 0};
    insertion_sort<vector<int>::iterator>(input.begin(), input.end());

    vector<int> expected {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(input, expected);
}

TEST(merge_sort_top_down, MergeSort) {
    vector<int> input {1, 8, 3, 6, 5, 4, 7, 2, 9, 0};
    merge_sort_top_down<vector<int>::iterator>(input.begin(), input.end());

    vector<int> expected {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(input, expected);

    input = {1, 8, 3, 6, 5, 4, 7, 2, 9, 0};
    merge_sort_bottom_up<vector<int>::iterator>(input.begin(), input.end());
    EXPECT_EQ(input, expected);

    std::cout << "{1, 0}" << std::endl;
    input = {1, 0};
    expected = {0, 1};
    merge_sort_top_down_debug<vector<int>::iterator>(input.begin(), input.end());
    EXPECT_EQ(input, expected);

    std::cout << "{1, 3, 2}" << std::endl;
    input = {1, 3, 2};
    expected = {1, 2, 3};
    merge_sort_top_down_debug<vector<int>::iterator>(input.begin(), input.end());
    EXPECT_EQ(input, expected);

    std::cout << "{10, 30, 27, 50, 60, 40, 20}" << std::endl;
    input = {10, 30, 29, 50, 60, 40, 28, 20};
    expected = {10, 20, 28, 29, 30, 40, 50, 60};
    merge_sort_top_down_debug<vector<int>::iterator>(input.begin(), input.end());
    EXPECT_EQ(input, expected);

    std::cout << "{10, 30, 27, 50, 60, 40, 20}" << std::endl;
    input = {10, 30, 27, 50, 60, 40, 28, 20};
    expected = {10, 20, 27, 28, 30, 40, 50, 60};
    merge_sort_top_down_debug<vector<int>::iterator>(input.begin(), input.end());
    EXPECT_EQ(input, expected);
}

TEST(merge_sort_list_bottom_up, MergeSortLinkedList) {
    ListNode list1[100];
    for (int i = 0; i < 99; ++i) {
        list1[i].val = 99 - i;
        list1[i].next = &list1[i + 1];
    }
    list1[99].val = 0;

    ListNode* res = merge_sort_list_bottom_up(&list1[0]);
    for (auto [p, i] = std::tuple{res, 0}; p != nullptr; p = p->next) {
        EXPECT_EQ(p->val, i++);
    }

    ListNode list2[2];
    list2[0].val = 1; list2[0].next = &list2[1];
    list2[1].val = 0;
    res = merge_sort_list_bottom_up(&list2[0]);
    for (auto [p, i] = std::tuple{res, 0}; p != nullptr; p = p->next) {
        EXPECT_EQ(p->val, i++);
    }

    ListNode list3[1];
    list3[0].val = 0;
    res = merge_sort_list_bottom_up(&list3[0]);
    for (auto [p, i] = std::tuple{res, 0}; p != nullptr; p = p->next) {
        EXPECT_EQ(p->val, i++);
    }
}

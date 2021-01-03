#ifndef ACRUSH_MERGESORT_H
#define ACRUSH_MERGESORT_H

#include "StandardLibrary.h"

#include "ListNode.h"

using namespace std;

/**
 * Merge Sort: a common algorithmic paradigm based on recursion: divide-and-conquer
 *
 * Array, LinkedList
 *
 * Top-down, Bottom-up
 *
 */

template <typename ForwardIt>
void merge(ForwardIt first, ForwardIt mid, ForwardIt last) {
    while (first != mid && mid != last) {
        const auto iter = mid;
        first = upper_bound(first, mid, *mid);
        mid = upper_bound(mid, last, *first);
        rotate(first, iter, mid);
    }
}

// array top-down approach
template <typename ForwardIt>
void merge_sort_top_down(ForwardIt first, ForwardIt last) {
    const auto size = distance(first, last);
    if (size < 2)
        return;

    const auto mid = first + size / 2 + size % 2;

    merge_sort_top_down(first, mid);
    merge_sort_top_down(mid, last);
    merge(first, mid, last);
}

// array bottom-up approach
template <typename ForwardIt>
void merge_sort_bottom_up(ForwardIt first, ForwardIt last) {
    const auto size = distance(first, last);
    for (auto width = 1; width < size; width *= 2)
        for (auto i = 0; i < size; i += width * 2) {
            ForwardIt second = first + i;
            for (auto w = width; w > 0 && second != last; --w)
                second++;
            ForwardIt boundary = first + i;
            for (auto w = 2 * width; w > 0 && boundary != last; --w)
                boundary++;
            merge(first + i, second, boundary);
        }
}

// linked list top-down approach
ListNode* merge_two_lists(ListNode* l1, ListNode* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->val < l2->val) {
        l1->next = merge_two_lists(l1->next, l2);
        return l1;
    } else {
        l2->next = merge_two_lists(l1, l2->next);
        return l2;
    }
}

ListNode* merge_sort_list_top_down(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode *fast = head, *slow = head, *pre = head;
    while (fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;

    return merge_two_lists(merge_sort_list_top_down(head), merge_sort_list_top_down(slow));
}

// linked list bottom-up approach
pair<ListNode*, ListNode*> merge2lists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0), *res = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            res->next = l1;
            l1 = l1->next;
        } else {
            res->next = l2;
            l2 = l2->next;
        }
        res = res->next;
    }
    if (l1)
        res->next = l1;
    else if (l2)
        res->next = l2;
    while (res->next)
        res = res->next;
    return make_pair(dummy.next, res); // return the head & tail of merged list
}

ListNode* split(ListNode* head, int n) {
    while (--n && head)
        head = head->next;
    ListNode* rest = head ? head->next : nullptr;
    if (head)
        head->next = nullptr;
    return rest;
}

ListNode* merge_sort_list_bottom_up(ListNode* head) {
    if (!head || !head->next)
        return head;

    int len = 1;
    ListNode* cur = head;
    while (cur = cur->next)
        ++len;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *l, *r, *tail;
    for (int width = 1; width < len; width *= 2) {
        cur = dummy.next;
        tail = &dummy;

        while (cur) {
            l = cur;
            r = split(l, width);
            cur = split(r, width);
            auto merged = merge2lists(l, r);
            tail->next = merged.first;
            tail = merged.second;
        }
    }

    return dummy.next;
}

// debug
template <typename ForwardIt>
void merge_debug(ForwardIt first, ForwardIt mid, ForwardIt last) {
    auto begin = first;
    cout_green("merge_debug: current range (inclusive): ");
    for (ForwardIt it = first; it != last; ++it)
        cout << *it << " ";
    cout << endl;

    while (first != mid && mid != last) { // [first, mid, last]
        const auto iter = mid;

        begin = first;
        cout_green("while loop: sort range (inclusive): ");
        for (ForwardIt it = first; it != last; ++it) {
            if (it == iter)
                cout_green(to_string(*it));
            else
                cout << *it << " ";
        }
        cout << endl;

        first = upper_bound(first, mid, *mid);
        cout_red("first's index") << first - begin << endl;

        cout_red("iter's index") << iter - begin << endl;

        mid = upper_bound(mid, last, *first);
        cout_red("mid's index") << mid - begin << endl;

        rotate(first, iter, mid);
    }
}

template <typename ForwardIt>
void merge_sort_top_down_debug(ForwardIt first, ForwardIt last) {
    const auto size = distance(first, last);
    if (size < 2)
        return;

    const auto mid = first + size / 2 + size % 2;
    cout_cyan("merge_sort_top_down_debug: mid's offset: ") << mid - first << endl;

    merge_sort_top_down_debug(first, mid);
    merge_sort_top_down_debug(mid, last);
    merge_debug(first, mid, last);
}

#endif //ACRUSH_MERGESORT_H

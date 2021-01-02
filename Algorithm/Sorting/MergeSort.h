#ifndef ACRUSH_MERGESORT_H
#define ACRUSH_MERGESORT_H

#include "StandardLibrary.h"

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

// linked list bottom-up approach

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

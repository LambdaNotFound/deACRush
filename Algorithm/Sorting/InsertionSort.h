#ifndef ACRUSH_INSERTIONSORT_H
#define ACRUSH_INSERTIONSORT_H

#include "StandardLibrary.h"

using namespace std;

/**
 * insertion sort
 */

template <typename I>
void insertion_sort(I first, I last) {
    const auto size = distance(first, last);
    for (auto i = first; i < first + size; ++i)
        rotate(upper_bound(first, i, *i), i, i+1);
}

#endif //ACRUSH_INSERTIONSORT_H

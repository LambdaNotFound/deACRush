#ifndef ACRUSH_MONOTONICQUEUE_H
#define ACRUSH_MONOTONICQUEUE_H

#include "StandardLibrary.h"

using namespace std;

/**
 * Monotonic queue impl with template class
 *
 * keep tracking max element in the queue
 */

template <class T>
class MonotonicQueue {
public:
    void push(T element) {
        while (!deq.empty() && deq.back() < element)
            deq.pop_back();

        deq.push_back(element);
    }

    // pop the max element
    void pop() {
        deq.pop_front();
    }

    // get the max element
    T max() const {
        return deq.front();
    }

    size_t size() const {
        return deq.size();
    }

private:
    deque<T> deq;
};

#endif //ACRUSH_MONOTONICQUEUE_H

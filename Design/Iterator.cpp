#include "Iterator.h"

// 281. Zigzag Iterator
int Iterator::ZigzagIterator::nextFollowUp() {
    auto p = q.front(); q.pop();
    if (p.first + 1 != p.second)
        q.push(make_pair(p.first + 1, p.second));

    return *p.first;
}

bool Iterator::ZigzagIterator::hasNextFollowUp() {
    return !q.empty();
}

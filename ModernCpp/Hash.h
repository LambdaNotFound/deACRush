#ifndef ACRUSH_HASH_H
#define ACRUSH_HASH_H

#include "StandardLibrary.h"

using namespace std;

// std::pair, as well as std::tuple
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

template <class T1, class T2, class T3>
using unordered_map_pair_as_key = unordered_map<pair<T1, T2>, T3, pair_hash>;

#endif //ACRUSH_HASH_H

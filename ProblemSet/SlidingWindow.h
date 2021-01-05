#ifndef ACRUSH_SLIDINGWINDOW_H
#define ACRUSH_SLIDINGWINDOW_H

#include "StandardLibrary.h"

using namespace std;

class SlidingWindow {
/*
 * 438. Find All Anagrams in a String
 *
 * i. SlidingWindow + HashMap
 *     hashmap[x]-- > 0 right move in
 *     hashmap[x]++ >= 0 left move out
 */
public:
    vector<int> findAnagrams(string s, string p);

};

#endif //ACRUSH_SLIDINGWINDOW_H

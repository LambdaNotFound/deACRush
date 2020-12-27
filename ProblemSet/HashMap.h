#ifndef ACRUSH_HASHMAP_H
#define ACRUSH_HASHMAP_H

#include "StandardLibrary.h"

using namespace std;

class HashMap {
/*
 * 3. Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * follow up: without repeating k times?
 *
 * i. HashMap + TwoPointers, HashMap -> bitmap or vector<int> map(128, -1) <= LIKE T: O(n)
 * ii. HashSet
 *
 * 30. Substring with Concatenation of All Words
 * 76. Minimum Window Substring
 */
public:
    int lengthOfLongestSubstring(string s);
};

#endif //ACRUSH_HASHMAP_H

#ifndef ACRUSH_HASHMAP_H
#define ACRUSH_HASHMAP_H

#include "StandardLibrary.h"

using namespace std;

class HashMap {
/*
 * 1. Two Sum
 *
 * i. HashMap<num, index>: look up delta = target - nums[i] <= LIKE
 *
 * 167. Two Sum II - Input array is sorted
 */
public:
    vector<int> twoSum(vector<int>& nums, int target);

/*
 * 170. Two Sum III - Data structure design
 *
 * if (delta == value - key) , needs to check if count(delta) > 1
 *
 * i. HashMap<num, count>
 * ii. unordered_multiset<int>
 */
public:
    class TwoSum {
    public:
        void add(int number) {
            ++hashMap[number];
        }
        bool find(int value) {
            for (auto a : hashMap) {
                int t = value - a.first;
                if ((t != a.first && hashMap.count(t)) || (t == a.first && a.second > 1)) {
                    return true;
                }
            }
            return false;
        }
    private:
        unordered_map<int, int> hashMap;
    };


/*
 * 3. Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * follow up: without repeating k times?
 *
 * i. HashMap + TwoPointers <= LIKE T: O(n)
 * ii. HashSet <= LIKE T: O(n)
 *
 * 30. Substring with Concatenation of All Words
 * 76. Minimum Window Substring
 */
public:
    int lengthOfLongestSubstring(string s);

public:
    int lengthOfLongestSubstringHashSet(string s);

public:
    int lengthOfLongestSubstringFollowUp(string s, int k);

/*
 * 316. Remove Duplicate Letters
 * 1081. Smallest Subsequence of Distinct Characters
 *
 * Return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
 *
 * i. HashMap to count occurrence
 */
public:
    string removeDuplicateLetters(string s);

public:
    string smallestSubsequence(string s);
};

#endif //ACRUSH_HASHMAP_H

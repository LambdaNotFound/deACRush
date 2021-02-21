#ifndef ACRUSH_SLIDINGWINDOW_H
#define ACRUSH_SLIDINGWINDOW_H

#include "StandardLibrary.h"

using namespace std;

class SlidingWindow {
/*
 * 30. Substring with Concatenation of All Words
 *
 * You are given a string s and an array of strings words of the same length.
 * Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.
 *
 * i. SlidingWindow with a HashMap couting word's occurrence
 */
public:
    vector<int> findSubstring(string s, vector<string>& words);

/*
 * 76. Minimum Window Substring
 *
 * Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".
 *
 * i. SlidingWindow
 */
public:
    string minWindow(string s, string t);

/*
 * 438. Find All Anagrams in a String
 *
 * i. SlidingWindow
 */
public:
    vector<int> findAnagrams(string s, string p);

/*
 * 567. Permutation in String
 *
 * i. SlidingWindow
 */
public:
    bool checkInclusion(string s1, string s2);

/*
 * 159 Longest Substring with At Most Two Distinct Characters
 *
 */
public:

/*
 * 340 Longest Substring with At Most K Distinct Characters
 */
public:

/*
 * 395 Longest Substring with At Least K Repeating Characters
 */
public:

};

#endif //ACRUSH_SLIDINGWINDOW_H

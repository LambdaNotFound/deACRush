#ifndef ACRUSH_STRINGMATCHING_H
#define ACRUSH_STRINGMATCHING_H

#include "StandardLibrary.h"

using namespace std;

class StringMatching {
/**
 * String Matching
 * Longest Common Substring
 * Longest Common Subsequence
 */

/*
 * 28. Implement strStr()
 *
 * i. brute force
 * ii. KMP
 */
public:
    int strStrBruteForce(string haystack, string needle);

public:
    int strStr(string haystack, string needle);
private:
    vector<int> computeTable(const string& haystack);

/*
 * 718. Maximum Length of Repeated Subarray
 *
 * i. brute force: enumerating all substrings
 * ii. recursive approach:
 * iii. DP
 */
public:
    int findLengthBruteForce(vector<int>& A, vector<int>& B);

public:
    int findLength(vector<int>& A, vector<int>& B);
private:
    int findLengthHelper(vector<int>& A, int m, vector<int>& B, int n, int res);

/*
 * 1143. Longest Common Subsequence
 *
 * i*. brute force: enumerating all subsequeces
 * ii. recursive approach:
 * iii. DP
 */
public:
    int longestCommonSubsequence(string A, string B);
private:
    int longestCommonSubsequenceHelper(string A, int m, string B, int n, int len);

};

#endif //ACRUSH_STRINGMATCHING_H

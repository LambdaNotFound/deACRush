#ifndef ACRUSH_DYNAMICPROGRAMMING_H
#define ACRUSH_DYNAMICPROGRAMMING_H

#include "StandardLibrary.h"

using namespace std;

class DynamicProgramming {
/**
 * String related: longest substring, parlindrom, etc.
 */

 /*
  * 5. Longest Palindromic Substring
  *
  * i. DP:
  *    dp[i][j] stores if substring s[i, j] is palindromic
  *
  *    dp[i][j] = (a). true if i == j
  *               (b). true if i - j == 1 && s[i] == s[j]
  *               (c). dp[i + 1][j - 1] if s[i] == s[j]
  */
public:
    string longestPalindrome(string s);

public:
    string longestPalindromeOptimized(string s);

/*
 * 132. Palindrome Partitioning II
 *
 * i. DP x 2
 *    dp1[i][j] stores if substring s[i, j] is palindromic
 *    dp2[i] stores min cut at i
 *
 *    init: dp2[i] = i as single char is palindromic
 */
public:
    int minCut(string s);

/*
 * 10. Regular Expression Matching
 *
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where:
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)": e.g. ".....*"
 *
 *    dp[i][j] stores if s[0, i - 1] and p[0, j - 1] matches:
 *
 *    dp[0][0] = true
 *    dp[i][j] = (a). dp[i - 1][j - 1] if (p[j - 1] != '*') && (s[i - 1] == p[j - 1] || p[j - 1] == '.')
 *               (b). dp[i][j - 2]     if (p[j - 1] == '*') // '*' Matches zero of the preceding char
 *               (c). dp[i - 1][j]     if (p[j - 1] == '*') && (s[i - 1] == p[j - 2] || p[j - 2] == '.') // '*' Matches one preceding char
 */
public:
    bool isMatch(string s, string p);

public:
    bool isMatchOptimized(string s, string p);

public:
    bool isMatchRecursive(string s, string p);

/*
 * 44. Wildcard Matching
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 *    dp[i][j] stores if s[0, i - 1] and p[0, j - 1] matches:
 *
 *    dp[0][0] = true, dp[0][j] = dp[0][j - 1] if p[j - 1] == '*'
 *    dp[i][j] = (a). dp[i - 1][j - 1] if (p[j - 1] != '*') && (s[i - 1] == p[j - 1] || p[j - 1] == '?')
 *               (b). dp[i][j - 1]     if (p[j - 1] == '*') // '*' Matches zero of the preceding char
 *               (c). dp[i - 1][j]     if (p[j - 1] == '*') // '*' Matches one preceding char
 */
public:
    bool isWildcardMatch(string s, string p);

public:
    bool isWildcardMatchOptimized(string s, string p);

public:
    bool isWildcardMatchRecursive(string s, string p);

/*
 * 72. Edit Distance
 *
 * i. Recursive approach: helper(word1, i, word2, j, memoTable)
 *     if (word1[i] == word2[j])
 *         helper(word1, i + 1, word2, j + 1, memoTable)
 *     else
 *         insert: helper(word1, i, word2, j + 1, memoTable)
 *         delete: helper(word1, i + 1, word2, j, memoTable)
 *         replace: helper(word1, i + 1, word2, j + 1, memoTable)
 *         min(insert, delete, replace) + 1
 *
 * ii. DP:
 *    dp[i][j] stores Edit Distance between word1[0, i - 1], word2[0, j - 1]
 *
 *
 *    dp[i][j] = (a). dp[i - 1][j - 1] if (word1[i - 1] == word2[j - 1])
 *               (b). min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
 */
public:
    int minDistance(string word1, string word2);

public:
    int minDistanceOptimized(string word1, string word2);

/*
 * 87. Scramble String
 *
 * a).
 * s1 [0, ... k - 1, k, ... n - 1]
 *            |
 * s2 [0, ... k - 1, k, ... n - 1]
 *
 * b).
 * s1 [0, ... k - 1,         k, ... n - 1]
 *                      \
 * s2 [0, ... n - k - 1, n - k, ... n - 1]
 *
 *    dp[i][j][k] stores if substrings start at i/j are scramble split with length k:
 *
 *    dp[i][j][1] = s1[i] == s2[j];
 *    a). dp[i][j][k] = dp[i][j][k] && dp[i + k][j + k][len - k])
 *    b). dp[i + k][j][len - k] && dp[i][j + len - k][k]
 */
public:
    bool isScramble(string s1, string s2);

public:
    bool isScrambleRecursive(string s1, string s2);
private:
    bool isScrambleRecursiveHelper(string& s1, string& s2, unordered_map<string, bool>& memo);

/*
 * 139. Word Break
 *
 *    dp[i] stores if substring ends at i - 1 has a valid sequence:
 *
 *    dp[i] = true if (a). s.substr(0, i) is a word in dict
 *                    (b). dp[j] == true AND substr(j, i - j) is a word in dict: [0, j - 1], [j, i - 1]
 */
public:
    bool wordBreak(string s, vector<string>& wordDict);

/*
 * 140. Word Break II
 *
 * i. recursion w/ memorization
 */
public:
    vector<string> wordBreakII(string s, vector<string>& wordDict);
private:
    vector<string> wordBreakIIHelper(string& s, vector<string>& wordDict, unordered_map<string, vector<string>>& memo);

/**
 * 2D matrix with value dependents on neighbor cells
 */

/*
 * 70. Climbing Stairs
 *
 * Each time you can either climb 1 or 2 steps.
 *
 *    dp[i] stores count of combinations at i:
 *
 *    dp[0] = 1, dp[1] = 1
 *    dp[i] = dp[i - 1] + dp[i - 2];
 */
public:
    int climbStairs(int n);

public:
    int climbStairsOptimized(int n);

};

#endif //ACRUSH_DYNAMICPROGRAMMING_H

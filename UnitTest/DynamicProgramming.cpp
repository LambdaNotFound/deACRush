#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../Algorithm/String/StringMatching.h"
#include "../ProblemSet/DynamicProgramming.h"

using namespace std;

TEST(L140WordBreakII, DynamicProgramming) {
    DynamicProgramming sln;

    string s = "catsanddog";
    vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
    vector<string> expected = { "cats and dog", "cat sand dog" };

    vector<string> result = sln.wordBreakII(s, wordDict);
    EXPECT_THAT(result, ::testing::UnorderedElementsAreArray(expected));
}

TEST(L718MaximumLengthOfRepeatedSubarray, StringMatching) {
    StringMatching sln;

    vector<int> A = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 };
    vector<int> B = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
    int expected = 9;
    int res = sln.findLengthBruteForce(A, B);
    EXPECT_EQ(res, expected);

    A = { 1, 0, 1, 0, 0, 0, 0, 0, 1, 1 };
    B = { 1, 1, 0, 1, 1, 0, 0, 0, 0, 0 };
    expected = 6;
    res = sln.findLengthDP(A, B);
    EXPECT_EQ(res, expected);

    A = { 1, 2, 6, 3, 4 };
    B = { 1, 2, 5, 3, 4 };
    expected = 2;
    res = sln.findLength(A, B);
    EXPECT_EQ(res, expected);
}

TEST(L1143LongestCommonSubsequence, StringMatching) {
    StringMatching sln;

    string a = "hofubmnylkra";
    string b = "pqhgxgdofcvmr";
    int expected = 5;
    int res = sln.longestCommonSubsequence(a, b);
    EXPECT_EQ(res, expected);

    a = "ylqpejqbalahwr";
    b = "yrkzavgdmdgtqpg";
    expected = 3;
    res = sln.longestCommonSubsequenceDP(a, b);
    EXPECT_EQ(res, expected);
}

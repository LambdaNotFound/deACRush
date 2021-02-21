#include "gtest/gtest.h"

#include "../ProblemSet/SlidingWindow.h"

using namespace std;

TEST(L30SubstringWithConcatenationOfAllWords, SlidingWindow) {
    SlidingWindow sln;
    auto s = "wordgoodgoodgoodbestword";
    vector<string> words = { "word", "good", "best", "good" };
    vector<int> expected = { 8 };

    auto res = sln.findSubstring(s, words);
    EXPECT_EQ(res, expected);
}

TEST(L76MinimumWindowSubstring, SlidingWindow) {
    SlidingWindow sln;
    auto s = "ADOBECODEBANC";
    auto t = "ABC";
    auto expected = "BANC";

    auto res = sln.minWindow(s, t);
    EXPECT_EQ(res, expected);
}

TEST(L438FindAllAnagramsInAString, SlidingWindow) {
    SlidingWindow sln;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> expected = {0, 6};

    auto res = sln.findAnagrams(s, p);
    EXPECT_EQ(res, expected);
}

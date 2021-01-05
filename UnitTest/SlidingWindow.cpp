#include "gtest/gtest.h"

#include "../ProblemSet/SlidingWindow.h"

using namespace std;

TEST(L438FindAllAnagramsInAString, SlidingWindow) {
    SlidingWindow sln;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> expected = {0, 6};

    auto res = sln.findAnagrams(s, p);
    EXPECT_EQ(res, expected);
}

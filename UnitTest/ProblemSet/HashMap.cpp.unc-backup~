#include "gtest/gtest.h"

#include "../../ProblemSet/HashMap.h"

using namespace std;

TEST(L3LongestSubstringWithoutRepeatingCharacters, HashMap)
{
    HashMap sln;
    string input = "abcabcbb";
    int expected = 3;

    int res = sln.lengthOfLongestSubstring(input);
    EXPECT_EQ(res, expected);

    input = "aa";
    expected = 1;
    res = sln.lengthOfLongestSubstring(input);
    EXPECT_EQ(res, expected);
}
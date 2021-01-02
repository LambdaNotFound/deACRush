#include "gtest/gtest.h"

#include "../ProblemSet/HashMap.h"

using namespace std;

TEST(L3LongestSubstringWithoutRepeatingCharacters, HashMap) {
    HashMap sln;
    string input = "abcabcbb";
    int expected = 3;

    int res = sln.lengthOfLongestSubstring(input);
    EXPECT_EQ(res, expected);

    input = "aa";
    expected = 1;
    res = sln.lengthOfLongestSubstringHashSet(input);
    EXPECT_EQ(res, expected);

    // follow-up, without repeating k times
    int k = 3;
    input = "abcabcbb";
    expected = 6;

    res = sln.lengthOfLongestSubstringFollowUp(input, k);
    EXPECT_EQ(res, expected);

    k = 2;
    input = "cccccc";
    expected = 1;

    res = sln.lengthOfLongestSubstringFollowUp(input, k);
    EXPECT_EQ(res, expected);
}

TEST(L170TwoSumIII, HashMap) {
    HashMap::TwoSum sln;
    sln.add(2);
    bool res = sln.find(4);
    bool expected = false;
    EXPECT_EQ(res, expected);

    sln.add(3);
    sln.add(1);
    res = sln.find(3);
    expected = true;
    EXPECT_EQ(res, expected);
}

#include "gmock/gmock.h"
#include "gtest/gtest.h"

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

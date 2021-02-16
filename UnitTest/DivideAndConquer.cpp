#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../ProblemSet/DivideAndConquer.h"

using namespace std;

TEST(L169MajorityElement, DivideAndConquer) {
    DivideAndConquer sln;

    vector<int> input1 = { 3, 2, 3 };
    int expected = 3;

    int result = sln.majorityElement(input1);
    EXPECT_EQ(result, expected);
}

TEST(L241DifferentWaysToAddParentheses, DivideAndConquer) {
    DivideAndConquer sln;

    string input1 = "2-1-1";
    vector<int> expected = { 2, 0 };

    auto result = sln.diffWaysToCompute(input1);
    EXPECT_EQ(result, expected);
}

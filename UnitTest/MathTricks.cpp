#include "gtest/gtest.h"

#include "../ProblemSet/MathTricks.h"

using namespace std;

TEST(L238ProductOfArrayExceptSelf, MathTricks) {
    MathTricks sln;
    vector<int> input = {1, 2, 3, 4};
    vector<int> expected = {24, 12, 8, 6};

    auto res = sln.productExceptSelf(input);
    EXPECT_EQ(res, expected);
}

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../ProblemSet/Backtracking.h"

using namespace std;

TEST(L46Permutations, Backtracking) {
    Backtracking sln;

    vector<int> input = { 1, 2, 3 };
    vector<vector<int> > expected = { { 1, 2, 3 }, { 1, 3, 2 }, { 2, 1, 3 }, { 2, 3, 1 }, { 3, 1, 2 }, { 3, 2, 1 } };

    vector<vector<int> > result = sln.permute(input);
    EXPECT_EQ(result, expected);

    result = sln.permuteBFS(input);
    EXPECT_THAT(result, ::testing::UnorderedElementsAreArray(expected));

    result = sln.permuteSwap(input);
    EXPECT_THAT(result, ::testing::UnorderedElementsAreArray(expected));
}

TEST(L47PermutationsII, Backtracking) {
    Backtracking sln;

    vector<int> input = { 3, 3, 0, 3 };
    vector<vector<int> > expected = { { 0, 3, 3, 3 }, { 3, 0, 3, 3 }, { 3, 3, 0, 3 }, {3, 3, 3, 0 } };

    vector<vector<int> > result = sln.permuteUnique(input);
    EXPECT_EQ(result, expected);
}

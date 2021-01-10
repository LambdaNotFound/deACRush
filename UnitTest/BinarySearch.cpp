#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../ProblemSet/BinarySearch.h"

using namespace std;

TEST(L4MedianOfTwoSortedArrays, BinarySearch) {
    BinarySearch sln;

    vector<int> input1 = { 1, 2 };
    vector<int> input2 = { 3 };
    double expected = 2.0;

    double result = sln.findMedianSortedArrays(input1, input2);
    EXPECT_EQ(result, expected);

    result = sln.findMedianSortedArraysGeneral(input1, input2);
    EXPECT_EQ(result, expected);

    input1 = { 1 };
    input2 = { 2, 3, 4, 5 };
    expected = 3.0;
    result = sln.findMedianSortedArraysGeneral(input1, input2);
    EXPECT_EQ(result, expected);
}

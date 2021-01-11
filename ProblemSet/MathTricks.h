#ifndef ACRUSH_MATHTRICKS_H
#define ACRUSH_MATHTRICKS_H

#include "StandardLibrary.h"

using namespace std;

class MathTricks {
/*
 * 6. ZigZag Conversion
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *     string convert(string s, int numRows);
 *
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N    <- first row
 * A   L S  I G
 * Y A   H R
 * P     I         <- last row
 *
 * i. use an array of string of size numRows to simulate the process <= LIKE!!
 *     vector<string> vec(numRows); ... vec[pos] += s[i++];
 *     v[0] P I N
 *     v[1] A L S I G
 *     v[2] Y A H R
 *     v[3] P I
 *
 * ii. Math: for each row, the vertical offset is: (2 * numRows - 2)
 *           for each row excluding first row and last row, the diagonal offset is: (2 * numRows - 2 - 2i)
 *
 */
public:
    string convert(string s, int numRows);

public:
    string convertMath(string s, int numRows);

/*
 * 31. Next Permutation
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place and use only constant extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 * STL: next_permutation()
 *
 * i. Math: start from the end of nums
 *   a. Find the largest index i such that nums[i] < nums[i + 1]. If no such index exists, just reverse nums.
 *   b. Find the largest index j > i such that nums[i] < nums[j].
 *   c. Swap nums[i] and nums[j].
 *   d. Reverse the sub-array nums[i + 1] to nums[end].
 *
 *   1  2  7  4  3  1
 *   1  2< 7  4  3< 1
 *   1  3 [7  4  2  1]
 *   1  3  1  2  4  7
 */
public:
    void nextPermutation(vector<int>& nums);

/*
 * 60. Permutation Sequence
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 *
 */
public:
    string getPermutation(int n, int k);

/*
 * 118. Pascal's Triangle
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 *
 * i. res[i][j] = res[i - 1][j - 1] + res[i - 1][j]
 *     vector<T>::resize(size, value);
 */
public:
    vector<vector<int> > generate(int numRows);

/*
 * 119. Pascal's Triangle II
 *
 * Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
 *
 *                 i
 * 1               0
 * 1, 1,           1
 * 1, 2, 1         2
 * 1, 3, 3, 1      3
 * 1, ...
 *
 * i. left to right: j = i, res[j] += res[j - 1];
 *     1D array
 */
public:
    vector<int> getRow(int rowIndex);

/*
 * 238. Product of Array Except Self
 *
 * i. 2-pass, left to right and right to left, store product in 1 array + 1 var
 */
public:
    vector<int> productExceptSelf(vector<int>&nums);

};

#endif //ACRUSH_MATHTRICKS_H

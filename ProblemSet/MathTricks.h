#ifndef ACRUSH_MATHTRICKS_H
#define ACRUSH_MATHTRICKS_H

#include "StandardLibrary.h"

using namespace std;

class MathTricks {
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

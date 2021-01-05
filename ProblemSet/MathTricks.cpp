#include "MathTricks.h"

// 118. Pascal's Triangle
vector<vector<int>> MathTricks::generate(int numRows) {
    vector<vector<int>> res(numRows, vector<int>());
    for (int i = 0; i < numRows; ++i) {
        res[i].resize(i + 1, 1);
        for (int j = 1; j < i; ++j)
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j]; // res[i - 1], previous row
    }
    return res;
}

// 119. Pascal's Triangle II
vector<int> MathTricks::getRow(int rowIndex) {
    vector<int> res(rowIndex + 1);
    res[0] = 1;
    for (int i = 1; i <= rowIndex; ++i)
        for (int j = i; j >= 1; --j)
            res[j] += res[j - 1];
    return res;
}

// 238. Product of Array Except Self
vector<int> MathTricks::productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);

    for (int i = 1; i < nums.size(); ++i)
        res[i] = nums[i - 1] * res[i - 1];

    int productRightToLeft = 1;
    for (int i = nums.size() - 2; i >= 0; --i) {
        productRightToLeft *= nums[i + 1];
        res[i] *= productRightToLeft;
    }

    return res;
}

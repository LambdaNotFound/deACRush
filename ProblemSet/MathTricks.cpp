#include "MathTricks.h"

// 6. ZigZag Conversion
string MathTricks::convert(string s, int numRows) {
    if (numRows <= 1)
        return s;

    string res;
    vector<string> vec(numRows);
    for (int i = 0; i < s.size();) {
        for (int pos = 0; pos < numRows && i < s.size(); ++pos)
            vec[pos] += s[i++];
        for (int pos = numRows - 2; pos > 0 && i < s.size(); --pos) // excluding first row and last row
            vec[pos] += s[i++];
    }
    for (auto &a: vec)
        res += a;

    return res;
}

string MathTricks::convertMath(string s, int numRows) {
    if (numRows <= 1)
        return s;

    string res;
    int offsetVertical = 2 * numRows - 2;
    for (int i = 0; i < numRows; ++i)
        for (int j = i; j < s.size(); j += offsetVertical) {
            res += s[j];
            int offsetDiagonal = j + offsetVertical - 2 * i;
            if (i != 0 && i != numRows - 1 && offsetDiagonal < s.size()) // excluding first and last rows
                res += s[offsetDiagonal];
        }

    return res;
}

// 31. Next Permutation
void MathTricks::nextPermutation(vector<int> &nums) {
    int i, j, n = nums.size();
    for (i = n - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
            for (j = n - 1; j > i; --j)
                if (nums[i] < nums[j])
                    break;

            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
            return;
        }
    }
    reverse(nums.begin(), nums.end());
}

/*
void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n - 2, j = n - 1;
    while (i >= 0 && nums[i] >= nums[i + 1])
        --i;
    if (i >= 0) {
        while (nums[j] <= nums[i])
            --j;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}
 */

// 60. Permutation Sequence
string MathTricks::getPermutation(int n, int k) {
    string res;
    string num = "123456789";
    vector<int> factorial(n, 1);
    for (int i = 1; i < n; ++i)  // [0!, 1!, 2!, ..., n - 1!]
        factorial[i] = factorial[i - 1] * i;

    k -= 1; // Kth is 1 based
    for (int i = 1; i <= n; ++i) { // [1, n], num's range
        int j = k / factorial[n - i];
        k %= factorial[n - i];
        res += num[j];
        num.erase(j, 1);
    }

    return res;
}

/*
string getPermutation(int n, int k) {
    string res;
    string num = "123456789";
    vector<int> f(n, 1);
    for (int i = 1; i < n; ++i)
        f[i] = f[i - 1] * i;
    --k;
    for (int i = n; i >= 1; --i) {
        int j = k / f[i - 1];
        k %= f[i - 1];
        res.push_back(num[j]);
        num.erase(j, 1);
    }
    return res;
}
 */

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

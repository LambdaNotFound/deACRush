#include "BitManipulation.h"

// 89. Gray Code
vector<int> BitManipulation::grayCode(int n) {
    vector<int> res;
    for (int i = 0; i < pow(2,n); ++i)
        res.push_back((i >> 1) ^ i);

    return res;
}

unsigned int BitManipulation::binaryToGray(unsigned int num) {
    return (num >> 1) ^ num;
}

unsigned int BitManipulation::grayToBinary(unsigned int num) {
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1) {
        num = num ^ mask;
    }
    return num;
}

// mirror arrangement
vector<int> grayCode(int n) {
    vector<int> res{0};
    for (int i = 0; i < n; ++i) {
        int size = res.size();
        for (int j = size - 1; j >= 0; --j) {
            res.push_back(res[j] | (1 << i));
        }
    }
    return res;
}

// 169. Majority Element
int BitManipulation::majorityElement(vector<int>& nums) {
    int res = 0, n = nums.size();
    for (int i = 0; i < 32; ++i) {
        int ones = 0, zeros = 0;
        for (int num : nums) {
            if (ones > n / 2 || zeros > n / 2)
                break;
            if ((num & (1 << i)) != 0)
                ++ones;
            else
                ++zeros;
        }
        if (ones > zeros)
            res |= (1 << i);
    }
    return res;
}

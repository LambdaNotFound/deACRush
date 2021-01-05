#include "MathTricks.h"

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

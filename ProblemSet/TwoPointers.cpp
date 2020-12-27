#include "TwoPointers.h"

// 18. 4Sum
vector<vector<int> > TwoPointers::fourSum(vector<int> &nums, int target) {
    vector<vector<int> > res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    vector<int> out{ nums[i], nums[j], nums[left], nums[right] };
                    res.push_back(out);
                    do
                        left++;
                    while (left < right && nums[left] == nums[left - 1]);
                    do
                        right--;
                    while (left < right && nums[right] == nums[right + 1]);
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }
    return res;
}

//  167. Two Sum II - Input array is sorted
vector<int> TwoPointers::twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
        int sum = numbers[l] + numbers[r];
        if (sum == target)
            return {l + 1, r + 1};
        else if (sum < target)
            ++l;
        else
            --r;
    }
    return {};
}

vector<int> TwoPointers::twoSumBinarySearch(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
        int t = target - numbers[i], left = i + 1, right = numbers.size(); // [..., i, [l, ..., r]]
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] == t)
                return {i + 1, mid + 1};
            else if (numbers[mid] < t)
                left = mid + 1;
            else
                right = mid;
        }
    }
    return {};
}
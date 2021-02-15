#include "Monotone.h"

#include "MonotonicQueue.h"

// 496. Next Greater Element I
vector<int> Monotone::nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> map;
    for (int i = nums2.size() - 1; i >= 0; --i) {
        while (!s.empty() && nums2[i] >= s.top())
            s.pop();
        int nextGreaterOnRight = s.empty() ? -1 : s.top();
        s.push(nums2[i]);
        map[nums2[i]] = nextGreaterOnRight;
    }

    vector<int> res;
    for (const auto& num : nums1)
        res.push_back(map[num]);

    return res;
}

// 503. Next Greater Element II
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);

    stack<int> s;
    for (int i = 2 * n - 1; i >= 0; --i) {
        while (!s.empty() && nums[i % n] >= s.top())
            s.pop();
        int nextGreaterOnRight = s.empty() ? -1 : s.top();
        s.push(nums[i % n]);
        res[i % n] = nextGreaterOnRight;
    }

    return res;
}

// 239. Sliding Window Maximum
vector<int> Monotone::maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    MonotonicQueue<int> monoq;
    for (int i = 0; i < nums.size(); ++i) {
        monoq.push(nums[i]);

        if (i + 1 >= k) {
            res.push_back(monoq.max());
            if (nums[i + 1 - k] == monoq.max())
                monoq.pop();
        }
    }

    return res;
}

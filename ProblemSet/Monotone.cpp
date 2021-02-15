#include "Monotone.h"

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
    deque<int> deq;
    for (int i = 0; i < nums.size(); ++i) {
        while (!deq.empty() && deq.back() < nums[i])
            deq.pop_back();
        deq.push_back(nums[i]);

        if (i - (k - 1) >= 0) { // window includes i, size of k
            int max = deq.front();
            res.push_back(max);
            if (nums[i - (k - 1)] == max)
                deq.pop_front();
        }
    }

    return res;
}

// monotone queue stores index
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> q;
    for (int i = 0; i < nums.size(); ++i) {
        if (!q.empty() && q.front() == i - k)
            q.pop_front();

        while (!q.empty() && nums[q.back()] < nums[i])
            q.pop_back();
        q.push_back(i);

        if (i >= k - 1)
            res.push_back(nums[q.front()]);
    }

    return res;
}

vector<int> Monotone::maxSlidingWindowMultiSet(vector<int>& nums, int k) {
    vector<int> res;
    multiset<int> ms;
    for (int i = 0; i < nums.size(); ++i) {
        if (i - k >= 0) // first left element outside of window
            ms.erase(ms.find(nums[i - k]));

        ms.insert(nums[i]);

        if (i - (k - 1) >= 0) // window includes i, size of k
            res.push_back(*ms.rbegin());
    }
    return res;
}

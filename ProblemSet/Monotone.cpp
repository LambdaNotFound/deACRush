#include "Monotone.h"

#include "MonotonicQueue.h"

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
